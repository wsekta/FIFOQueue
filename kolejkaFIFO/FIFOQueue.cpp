#include "FIFOQueue.h"

void QFDel( QueueFIFO* q ); //private



//=======================================
int QFCreate( QueueFIFO* q, int nSize )
{
	if ( nSize <= 0 )
	{
		perror( "QFCreate: too small size" );
		return 0;
	}

	if ( !q )
	{
		perror( "QFCreate: queue is not allocated" );
		return 0;
	}

	q->pTab = ( QUEUEITEM** )calloc( nSize, sizeof( QUEUEITEM* ) );
	if ( !( q->pTab ) )
	{
		perror( "QFCreate: allocation error" );
		return 0;
	}
	q->nSize = nSize;
	q->nHead = 0;
	q->nCurrSize = 0;
	q->nFirstFree = 0;
	return 1;
}



//=======================================
int QFEmpty( QueueFIFO* q )
{
	return !( q->nCurrSize );
}



//=======================================
void QFEnqueue( QueueFIFO* q, QUEUEITEM* x )
{
	if ( q->nCurrSize != q->nSize )
	{
		q->pTab[ q->nFirstFree ] = x;
		q->nCurrSize++;
		q->nFirstFree = ( q->nFirstFree == q->nSize - 1 ? 0 : q->nFirstFree + 1 );
	}
	else
		perror( "QFEnqueue: Queue is full" );
}



//=======================================
QUEUEITEM* QFDequeue( QueueFIFO* q )
{
	if ( !QFEmpty( q ) )
	{
		QUEUEITEM* p = q->pTab[ q->nHead ];
		QFDel( q );
		return p;
	}
	perror( "QFDequeue: Queue is empty" );
	return NULL;
}



//=======================================
void QFClear( QueueFIFO* q )
{
	QUEUEITEM** p = q->pTab;
	for ( int i = 0; i < q->nSize; i++ )
		if ( *p )
			free( *p++ );
		//*p++ = NULL;
	q->nCurrSize = 0;
	q->nHead = 0;
	q->nFirstFree = 0;
}



//=======================================
void QFRemove( QueueFIFO* q )
{
	/*QUEUEITEM** p = q->pTab;
	for ( int i = 0; i < q->nSize; i++ )
		if ( *p )
			free( *p++ );
		//*p++ = NULL;
	q->nCurrSize = 0;
	q->nHead = 0;
	q->nFirstFree = 0;*/
	QFClear( q );
	free( q->pTab );
	q->pTab = NULL;

	q->nSize = 0;
}



//=======================================
void QFDel( QueueFIFO* q )
{
	q->pTab[ q->nHead ] = NULL;
	q->nHead = ( q->nHead == q->nSize - 1 ? 0 : q->nHead + 1 );
	q->nCurrSize--;
}
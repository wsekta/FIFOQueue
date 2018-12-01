#include "FIFOQueue.h"

//queue with head

void QFCreate( QueueFIFO* q )
{
	QFIFOItem *p = ( QFIFOItem* )calloc( 1, sizeof( QFIFOItem ) );
	if ( !p )
		perror( "QFCreate: allocation error" );
	q->pHead = p;
	q->pTail = p;
}



//=======================================
int QFEmpty( QueueFIFO* q )
{
	return !( q->pHead->pNext );
}



//=======================================
void QFEnqueue( QueueFIFO* q, int x )
{
	QFIFOItem *p = ( QFIFOItem* )calloc( 1, sizeof( QFIFOItem ) );
	if ( !p )
		perror( "QFEnqueue: allocation error" );
	p->nKey = x;

	q->pTail->pNext = p;
	q->pTail = p;
}



//=======================================
int QFDequeue( QueueFIFO* q )
{
	if ( !QFEmpty( q ) )
	{
		int res = q->pHead->pNext->nKey;
		QFDel( q );
		return res;
	}
	perror( "QFDequeue: queueu empty" );
	return 0;
}



//=======================================
void QFClear( QueueFIFO* q )
{
	while ( !QFEmpty( q ) )
		QFDel( q );
}



//=======================================
void QFRemove( QueueFIFO* q )
{
	QFClear( q );
}



//=======================================
void QFDel( QueueFIFO* q )
{
	if ( !QFEmpty( q ) )
	{
		QFIFOItem *p = NULL;
		if ( q->pHead->pNext->pNext )
			p = q->pHead->pNext->pNext;
		else
			q->pTail = q->pHead;
		free( q->pHead->pNext );
		q->pHead->pNext = p;
	}
}
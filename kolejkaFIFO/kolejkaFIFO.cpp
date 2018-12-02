#include "FIFOQueue.h"
#include <time.h>

#define TAB_SIZE 10

int main()
{
	QueueFIFO *q = ( QueueFIFO* )calloc( 1, sizeof( QueueFIFO ) );
	if ( !q )
	{
		perror( "main: allocation error" );
		return 1;
	}
	if ( !QFCreate( q, 7 ) )
	{
		perror( "main: allocation error" );
		return 1;
	}

	QUEUEITEM* pTab = ( QUEUEITEM* )calloc( TAB_SIZE, sizeof( QUEUEITEM ) );
	QUEUEITEM* p = pTab;
	for ( int i = 0; i < TAB_SIZE; i++ )
		p++->nKey = i;
	p = pTab;
	for ( int i = 0; i < TAB_SIZE; i++ )
		QFEnqueue( q, p++ );
	for ( int i = 0; i < TAB_SIZE - q->nSize; i++ )
		printf( "%d\n", QFDequeue( q )->nKey );
	QFClear( q );
	QFDequeue( q );
	QFRemove( q );
	printf( "%p", q->pTab );
	return 0;
}

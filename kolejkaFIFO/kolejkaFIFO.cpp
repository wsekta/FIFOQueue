#include "FIFOQueue.h"

int main()
{
	QueueFIFO *q = ( QueueFIFO* )calloc( 1, sizeof( QueueFIFO ) );
	if ( !q )
		perror( "main: allocation error" );
	QFCreate( q );
	for ( int i = 0; i < 10; i++ )
		QFEnqueue( q, i );
	for ( int i =0 ; i < 5; i++ )
		printf( "%d\n", QFDequeue( q ) );
	QFClear( q );
	for ( int i = 0; i < 5; i++ )
		printf( "%d\n", QFDequeue( q ) );
	printf( "\n\n%p %p", q->pHead, q->pTail );
	return 0;
}

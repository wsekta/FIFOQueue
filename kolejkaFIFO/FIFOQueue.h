#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int nKey;
} QFIFOItem;

#define QUEUEITEM QFIFOItem

typedef struct // kolejka cykliczna
{
	QUEUEITEM** pTab; //dynamic table of QFIFOITEM poiters - pQueue
	int nHead;//index of the first item - nHead
	int nFirstFree;//index of the first empty item( one after last ) nTail
	//additional info cor cyclic queue
	int nSize;
	int nCurrSize;
} QueueFIFO;

int QFCreate( QueueFIFO* q, int nSize ); // queue inititating // ustawic tylko dwa wskazniki na NLL
int QFEmpty( QueueFIFO* q ); // if fifo empty return 1 else 0
void QFEnqueue( QueueFIFO* q, QUEUEITEM* x ); // insert new item at the end , wstawia do kolejki
QUEUEITEM* QFDequeue( QueueFIFO* q ); // take out the first item; sciagniecie( tak jak pop na stosie )
void QFClear( QueueFIFO* q ); // clears the queeu czysci kolejke, usuwa wszystkie dynamiczne elementy i ustawic wskazniki na NULL
void QFRemove( QueueFIFO* q ); // czysci i usuwa pozostalosci ( np pozostale wskazniki )
#ifndef MY_TRANSMISION_ITEM_DECLARATION_HEADER_INCLUDED____
#define MY_TRANSMISION_ITEM_DECLARATION_HEADER_INCLUDED____

#include "..\my_include\free_types_.h"

typedef struct TransmitionItemTag
{
	unsigned modusAddr, commandCode;
	ByteBuffPtr sendBegin, sendEnd, reciveBegin, reciveEnd;
    bool isBegin, isEnd;
} TransmitionItem;

#endif
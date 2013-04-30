#ifndef _ERRORHANDLE_H
#define _ERRORHANDLE_H

typedef struct Err Err;
#include "public.h"

//enum string to print
typedef struct Err{
	int errNum;
	int eLine;
}Err;

void errorInit();

#endif
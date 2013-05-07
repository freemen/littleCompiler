#include <stdio.h>
#include <stdlib.h>
//#include "hello.h"

typedef struct abc{
	int a;
	int b;
}abc;
main(){
	abc* aaa = (abc*)malloc(8*sizeof(abc));
	printf("sizeof aaa: %d, msize aaa: %d\n",sizeof(aaa), _msize(aaa));
	abc* bbb;
	memcpy(bbb, aaa, _msize(aaa));
	printf("sizeof bbb: %dmsize%d",sizeof(bbb),_msize(bbb));
//	hello(xz=>122,zxcv"dd");
dod(1,2);
}
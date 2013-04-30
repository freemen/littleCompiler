//#include "errorHandle.h"
#include "public.h"
#include <time.h>
#include <stdarg.h>

time_t t;
struct tm *lt;
char mtime[65] = {0};
FILE *elog;
bool logable;

void errorInit(){
	time(&t);
	error.errNum = -1;
	error.eLine = 1;
	if ((elog = fopen("e.log", "a+")) == null){
		printf("can't open e.log\n");
		logable = false;
		return;
	}else{
		fseek(elog, SEEK_SET, 0);
		logable = true;
	}
}

char *myTime(){
	lt = localtime(&t);
	strftime(mtime, 64, "%b,%dth,%Y, %H:%M:%S", lt);
	return mtime;
}

void logIt(const char* info, ...){
	//printf("%s --log: %s\n", myTime(),info);
	//printf("%4d%02d%02d %02d:%02d:%02d --log: %s\n",1900+lt->tm_year, 1+lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, info);
	va_list argList;
	va_start(argList, info);

	printf("%s --log: ", myTime());
	vfprintf(stdout, info, argList);
	printf("\n");
	if(logable){
		fprintf(elog, "%s --log: ", myTime());
		vfprintf(elog, info, argList);
		fprintf(elog, "\n");
	}
	
	va_end(argList);

}

void logE(const char* info, ...){
	va_list argList;
	va_start(argList, info);

	printf("%s --e: ", myTime());
	vfprintf(stdout, info, argList);
	printf("\n");
	if(logable){
		fprintf(elog, "%s --e: ", myTime());
		vfprintf(elog, info, argList);
		fprintf(elog, "\n");
	}
	
	va_end(argList);
}


void printErrorInfo(const char* info){
//		printf("%s --e: %s\n", myTime(),info);
//	if(logable)
//		fprintf(elog, "%s --e: %s\n", myTime(), info);
}

void errFinish(){
	fclose(elog);
}
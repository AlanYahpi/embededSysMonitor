
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define TICS 100

#ifndef PIDPATH
#define PIDPATH "/proc/91363/stat"
#endif


static inline int startPID(int * start, char pidPath [50], short * pidB ){
	char tmp[2560];
	char * token;



	FILE * file = fopen(pidPath, "r");
	if (!file) {printf("Error finding PID"); return 1;} else {*pidB = 1;}

	fgets(tmp, sizeof(tmp), file);
	strtok(tmp, " ");


	for (int i; i<27;i++){
		token = strtok(NULL, " ");
	}

	*start = strtol(token, NULL, 10);

	printf("%d\n", *start);
	
	fclose(file);
	return 0;
	
}

static inline void uptimef(float * uptime){
	FILE * filevar = fopen("/proc/uptime", "r");
	char tmp[50];

	fgets(tmp, sizeof(tmp), filevar);
	char * token = strtok(tmp, " ");


	*uptime = strtof(token,NULL);
	
	fclose(filevar);
}

static inline void pid(int startPid, int UPtime, char pidPath[50]){

	char string[256];			//if the system is too big, increase this 	def 50
	FILE * file = fopen(pidPath, "r");
	int utime, stime; 

	fseek(file,0,SEEK_SET);
	fgets(string, sizeof(string), file);
	char * token = strtok(string, " ");


	for (int i = 0; i < 13; i++){
		token = strtok(NULL, " ");
	}

	utime = strtol(token, NULL, 10);
	token = strtok(NULL, " ");
	stime = strtol(token, NULL, 10);


	float cpuPID =( (float)	(utime + stime) /TICS        /
				(UPtime - (startPid  / TICS))      *100 );

	printf("\n%s\n", pidPath);
//	printf("utime: %i\n",utime);
	//printf("stime: %i\n",stime);


	printf("PID total CPU usage: %0.9lf%%\n",cpuPID);


	

	fclose(file);


}

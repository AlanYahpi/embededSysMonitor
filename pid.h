#define TICS 100

#ifndef PIDPATH
#define PIDPATH "/proc/2242/stat"
#endif

static inline void startPID(int * start){
	char tmp[10];
	FILE * file = popen("awk '{print $22}' /proc/2242/stat", "r");
	
	fgets(tmp, sizeof(tmp), file);
	*start = strtol(tmp, NULL, 10);
	
	fclose(file);
	
}

static inline void uptimef(float * uptime){
	FILE * filevar = fopen("/proc/uptime", "r");
	char tmp[50];

	fgets(tmp, sizeof(tmp), filevar);
	char * token = strtok(tmp, " ");


	*uptime = strtof(token,NULL);
	
	fclose(filevar);
}

static inline void pid(int startPid, int UPtime){

	char string[256];			//if the system is too big, increase this 	def 50
	FILE * file = fopen(PIDPATH, "r");
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

	printf("\n%s\n", PIDPATH);
//	printf("utime: %i\n",utime);
	//printf("stime: %i\n",stime);


	printf("PID total CPU usage: %0.9lf%\n",cpuPID);


	

	fclose(file);


}

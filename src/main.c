#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#if __has_include("config.h")
#include "config.h"
#endif

#if __has_include("pid.h")
#include "pid.h"
#endif

#ifndef UNIT
#define UNIT 1073741.824
#endif

#ifndef UNITDIS
#define UNITDIS "GiB"
#endif

#ifndef CPUTIME
#define CPUTIME 1
#endif


void getMEM(int buffer[10]){
	char string[256];
	int i = 0;
	char * token;

	FILE * procf = fopen("/proc/meminfo", "r");
	fseek(procf,0,SEEK_SET);

	while (fgets(string, sizeof(string), procf) != NULL && i<5 ){
		strtok(string, " ");
		token = strtok(NULL, " ");
		buffer[i] = strtol(token, NULL, 10);
		i++;
	}	
		
	for (int i = 5; i<21; i++){
		fgets(string, sizeof(string), procf);
	}

	for (int i= 21, j = 5; i<26; i++){
		strtok(string, " ");
		token = strtok(NULL, " ");
		buffer[j] = strtol(token, NULL, 10);
		fgets(string, sizeof(string), procf);
		j++;


	}
	
	token = 0;

	fclose(procf);
	
}

void getCPU(int buffer[4]){
	
	FILE * statProc = fopen("/proc/stat", "r");
	int i=0;
	char statString[100];
	fseek(statProc,0,SEEK_SET);

	//searching for processor STAT (getting that to string)
	fgets(statString, sizeof(statString), statProc);
	char* token = strtok(statString, " "); //string tokenize

	while (token != NULL && i < 5){ //while the token character is not NULL
		
		buffer[i] = strtol(token, NULL, 10);		//convert token to long (decimal -10-)
								//in buffer[i]
		
		token = strtok(NULL, " ");			//clean token
		i++;						
		
	}

	fclose(statProc);




}


int main (){
	
	int cpuThreadA[5], cpuThreadB[5], memVal[10], startPid;
	
	/* PID
	startPID(&startPid);	
*/

	//update loop
	while (1){


	getCPU(cpuThreadA);
	sleep(CPUTIME);
	getCPU(cpuThreadB);
	

	system("clear");

	//aritmetics
	int initialRead = (cpuThreadA[1] + cpuThreadA[3] + cpuThreadA[4] ) ;
	int secondRead = (cpuThreadB[1] + cpuThreadB[3] + cpuThreadB[4] ) ;
	int totalTime = secondRead - initialRead;

	float percentageCPU = (float)  

			(totalTime - 
			(cpuThreadB[4] - cpuThreadA[4])	)	//idle
			/ totalTime* 100;

	

	printf("SYSTEM PROCS\n\n");


	//if the percentage is -nun (the result of a bit of time between both cpu reads)
	//infoms the usr to check the sleep time
	if (percentageCPU == percentageCPU){
		printf("CPU:\t\t%0.2f%\n\n", percentageCPU);
	} else {
		printf("percentage of cpu != self, =nun\n\n");
	}

	//GETTING RAM

	getMEM(memVal);
	
	/* FORMULAS
	 * Total use memmory = memtotal [0] - memfree [1]
	 * Aviable = memfree[1] + buffers[3] + cached[4]
	 *
	 * Non cache/buffer memmory = total used memmory - (buffers [3] + cached [4])
	 * Cached mem = cached [4] + SReclaimable[9] - shmem [6]
	 *
	 * swap = Swap total - Swap free (N/A)
	 */

	/*Sheet
	 * 0	total
	 * 1	free
	 * 2	avuable
	 * 3	bffer
	 * 4	cached
	 * 6	shmem
	 * 9	Sreclamablee
	 */


	int usedMem =  ( memVal[0] - memVal[1] ) ;
	int nonBuffer = usedMem - (memVal[3] + memVal[4]);


	//24 characters long
	//computer procs
	printf("MEMORY:\n\n");

	printf("Non buffered:\t%0.2f %s\n", nonBuffer / UNIT, UNITDIS);
	printf("Available mem: \t%0.2f %s\n", memVal[2] / UNIT, UNITDIS);
	printf("Total used:\t%0.2f / %0.2f %s\n", usedMem / UNIT, memVal[0] / UNIT, UNITDIS);

	//PID
	/*

	float UPtime;
	uptimef(&UPtime);
	//printf("uptime: %f", UPtime);

	pid(startPid, UPtime);
	//printf("Start PID: %ld\n", startPid);

	*/
	} //infinite loop break


return 0;
}

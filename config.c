#include <stdio.h>
#include <stdlib.h>

int binDec(int * unitTy, char print[1], int * denom){
	char input;
	printf("Select a type of unit by pressing:\n");
	printf("1\tFor binary\n");
	printf("2\tFor Decimal\n\n-> ");
	input = getchar();
	getchar();		//consume the New Line problem
	switch (input){
		case '1': {
			*unitTy = 1;
			*denom = 1024;
			print[0] = 'i';
		       	break;}
		case '2': {
			*unitTy = 2;
			*denom = 1000;
		       	break;}
		default: {
			system("clear");
			printf("Not a valid option\n\n");
			break;}
	}
}

void typeOfData(int * unit, char print[1], int * n){
	printf("Select a unit by pressing:\n");
	printf("1\tFor K%cB\n",print[0]);
	printf("2\tFor M%cB\n", print[0]);
	printf("3\tFor G%cB\n\n-> ", print[0]);
	char input = getchar();
	getchar();		//consume the New Line problem

	switch (input){
		case '1': {
			*unit = *n = 1;
		       	break;}
		case '2': {
			*unit = *n = 2;
		       	break;}
		case '3': {
			*unit = *n = 3;
			break;}
		default: {
			system("clear");
			printf("Not a valid option\n\n");
			break;}
	}
}



int main(){
	
	char printBD[1];		//stores an 'i' to be printed in a guide text
	int unitType = 0;		//	1 -> Binary	1024
					//	2 -> Decimal	1000
	int unit = 0;			//	1 -> K
					//	2 -> M
					//	3 -> G
	int denom;
	int n;
	double mult = 1;

	while (unitType == 0){
		binDec(&unitType,printBD, &denom);	//Asks for binary ot decimal
	}
	while (unit == 0 && unitType != 0){
		typeOfData(&unit, printBD, &n);		//asks for a unit type
	}
	
	int * cputime;
	while (cputime == 0) {
		printf("Setupdate interval -> ");
		scanf("%i", &cputime);
	}
	printf("%i", cputime);

	
	if (unitType == 2){	n--; 	}  //n-1

	while (n != 0){			//  ^ n
		mult *= denom;
		--n;
	}
	char display[4];

	if (unitType == 1){		//if binary
		mult = mult / 1000;
		display[1] = 'i';
	}

	
	//SETTING THE UNIT TYPE TO DISPLAY

	
	switch (unit){
		case 1:
			display[0] = 'K';
			break;
		case 2:
			display[0] = 'M';
			break;
		case 3:
			display[0] = 'G';
			break;
	}
	
	


	FILE * configf = fopen("config.h", "w");
	fprintf(configf, "#define UNIT %lf\n#define UNITDIS \"%sB\"\n#define CPUTIME %i", mult, display, cputime);
	fclose(configf);
return 0;
}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc, char **argv)
{
	srand (time(NULL));
	double procent;
	FILE *out= argc>1 ? fopen(argv[1], "w") : stdout;
	if (out==NULL){
		printf("Error");
		return 1;
	}
	int x,y;
	x=argc>2 ? atoi(argv[2]) : 10;
	y=argc>3 ? atoi (argv[3]) : 10;
	procent= argc>4 ? atof(argv[4]) : 0.5;
	double l;
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			l=rand()/(double)RAND_MAX;
			if (l<procent)
				fprintf(out, "1");
			else
				fprintf(out, "0");	
		}
		fprintf(out, "\n");	
	}
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "wczytaj.h"
#include "zapisz.h"
#include "ruchy.h"

/*typedef struct {
	int x;
	int y;
	int **data;
} plan_t; */

int main(int argc, char **argv)
{
	plan_t plansza;
	if (argc<3)
		return 1;
	int n=atoi(argv[1]);
	FILE *in = argc>2 ? fopen(argv[2], "r") : NULL;
	if (in==NULL)
		return 1;
	fclose(in);
	plansza=wczytaj(argv[2]);
	plansza=ruchy(n, plansza);
	FILE *out = argc>3 ? fopen(argv[3], "w"): fopen(argv[2],"w");
	if (out==NULL)
		out=fopen(argv[2], "w");
	zapisz(plansza, out);
	return 0;
}

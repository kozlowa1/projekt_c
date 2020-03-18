#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "wczytaj.h"
#include "zapisz.h"
#include "ruchy.h"
#include "rysuj.h"

/*typedef struct {
	int x;
	int y;
	int **data;
} plan_t; */

void nazwa(char *obraz, int dl, int i)
{
	int zer=1;
	int p=i;
	int l=1;
	while (p/10!=0)
	{
		zer++;
		p=p/10;
		l=l*10;
	}
	for(int o=0;o<zer;o++)
	{
		obraz[dl]='0'+(i/l);
		i=i%l;
		l=l/10;
		dl++;
	}
	obraz[dl]='.';
	obraz[dl+1]='p';
	obraz[dl+2]='n';
	obraz[dl+3]='g';
	obraz[dl+4]='\0';
}

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
	char obraz[100];
	char * pom = argc>4 ? argv[4] : "obrazy/out";
	int dl=0;
	while (pom[dl]!='\0'){
		obraz[dl]=pom[dl];
		dl++;
	}
	nazwa(obraz, dl, 0);
	rysuj (obraz, plansza);
	for(int i=0;i<n; i++){
		printf ("Rysunek %s utworzony\n", obraz);
		plansza=ruchy(1, plansza);
		nazwa(obraz, dl , i+1);
		rysuj(obraz,plansza);
	}
	printf("Rysunek %s utworzony\n", obraz);
	FILE *out = argc>3 ? fopen(argv[3], "w"): fopen(argv[2],"w");
	if (out==NULL)
		out=fopen(argv[2], "w");
	zapisz(plansza, out);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "wczytaj.h"

#define BUFSIZE 2000

plan_t wczytaj(char *plik)
{
	FILE *in = fopen(plik, "r");
	plan_t plansza;
	char buf [BUFSIZE];
	plansza.x=0;
	plansza.y=0;
	if (fgets(buf, BUFSIZE,in)==NULL)
	{
		return plansza;
	}
	int a=0;
	while(buf[a]!='\n'){
		if(buf[a]=='1' || buf[a]=='0')
			plansza.x++;
		a++;
	}
	plansza.y++;
	while(fgets(buf, BUFSIZE, in)!=NULL)
		plansza.y++;
	fclose(in);
	in = fopen(plik, "r");
	plansza.data=malloc(plansza.y* sizeof *plansza.data);
	for(int i=0;i<plansza.y;i++)
		plansza.data[i]=malloc(plansza.x * sizeof **plansza.data);
	for(int i=0;i<plansza.y;i++)
	{
		fgets(buf, BUFSIZE, in);
		a=0;
		int b=0;
		while(buf[a]!='\n'){
			if(buf[a]=='1'){
				plansza.data[b][i]=1;
				b++;
			}
			if(buf[a]=='0'){
				plansza.data[b][i]=0;
				b++;
			}
			a++;
		}
	}
	return plansza;
}

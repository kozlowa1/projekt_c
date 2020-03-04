#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "zapisz.h"
#include "wczytaj.h"

void zapisz (plan_t plansza, FILE *out)
{
	for(int i=0;i<plansza.y;i++){
		for(int j=0;j<plansza.x;j++){
			if (plansza.data[j][i]==0)
				fprintf(out, "0");
			else
				fprintf(out, "1");
		}
		fprintf(out,"\n");
	}
}

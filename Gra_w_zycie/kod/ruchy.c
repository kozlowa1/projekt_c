#include<stdio.h>
#include<stdlib.h>
#include "ruchy.h"
#include "wczytaj.h"

plan_t ruchy(int n, plan_t plansza){
	int tab[plansza.x+2][plansza.y+2];
	int tabpom[plansza.x+2][plansza.y+2];
	for (int i=0;i<plansza.x+2;i++)
	{
		tab[i][0]=0;
		tab[i][plansza.y+1]=0;
	}
	for(int i=1;i<plansza.y+1;i++){
		tab[0][i]=0;
		tab[plansza.x+1][i]=0;
		for(int j=1;j<plansza.x+1;j++)
			tab[j][i]=plansza.data[j-1][i-1];
	}
	int suma;
	for (int i=0;i<n;i++)
	{
		for(int j=1;j<plansza.y+1;j++){
			for(int k=1;k<plansza.x+1;k++){
				suma=0;
				if (tab[k-1][j-1]==1)
					suma++;
				if (tab[k-1][j]==1)
                                        suma++;
				if (tab[k-1][j+1]==1)
                                        suma++;
				if (tab[k][j+1]==1)
                                        suma++;
				if(tab[k][j-1]==1)
					suma++;
				if (tab[k+1][j-1]==1)
                                        suma++;
				if (tab[k+1][j]==1)
                                        suma++;
				if (tab[k+1][j+1]==1)
                                        suma++;
				tabpom[k][j]=tab[k][j];
				if (tab[k][j]==0 && suma==3)
					tabpom[k][j]=1;
				if(tab[k][j]==1 && (suma<2 || suma>3))
					tabpom[k][j]=0;
			}
		}
		for(int j=1;j<plansza.y+1;j++){
                        for(int k=1;k<plansza.x+1;k++){
				tab[k][j]=tabpom[k][j];
			}
		}

	}
	for(int j=1;j<plansza.y+1;j++){
        	for(int k=1;k<plansza.x+1;k++)
                	plansza.data[k-1][j-1]=tab[k][j];
                }
	return plansza;

} 

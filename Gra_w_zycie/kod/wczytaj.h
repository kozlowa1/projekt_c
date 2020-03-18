#ifndef WCZYTAJ_H
#define WCZYTAJ_H

typedef struct{
	int x;
	int y;
	int **data;
} plan_t;

plan_t wczytaj (char *plik);

#endif

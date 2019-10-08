#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UNUMBER 100

double timerank;
double timequicksort;

struct arg{
	float ave;
	int sum;
};

void show(int *, int);
void urand(int *, int);
void rank(int *, int);
void quicksort(int *, int);
struct arg operater(int *, int);

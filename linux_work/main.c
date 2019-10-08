#include "uhead.h"

int main(){
	int a[UNUMBER];
	struct arg t;
	urand(a, UNUMBER);
	show(a, UNUMBER);
	t = operater(a, UNUMBER);
	printf("sum = %d, ave = %f\n", t.sum, t.ave);
	rank(a, UNUMBER);
	show(a, UNUMBER);
	printf("%lf\n", timerank);
	return 0;
}

#include "uhead.h"

void rank(int* a, int n){
	clock_t start, finish;
    start = clock();

int left = 0,j=0,checked=0, right = n - 1;
	for (left = 0; left < right; left++)
	{
		for (j = 0; j < right - left; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j+1];
				a[j + 1]=tmp;
			}
		}
	}
	finish = clock();
    timerank = (double)(finish - start) / CLOCKS_PER_SEC;
}

void quicksort(int* a, int n){

	clock_t start, finish;
    start = clock();

	int i,j;
	int pivot = a[0];	//设置基准值 
	i = 0;
	j = n - 1;
	while(i < j){
		//大于基准值者保持在原位置 
		while(i < j && a[j] > pivot){	j--;} 
		if(i < j){
			a[i] = a[j];
			i++;
		}
		//不大于基准值者保持在原位置 
		while(i < j && a[i] <= pivot){ 	i++;} 
		if(i < j){
			a[j] = a[i];
			j--;
		}
	} 
	a[i] = pivot;	//基准元素归位 
		if(i > 1){
			//递归地对左子序列 进行快速排序
			quicksort(a,i); 
		}
		if(n-i-1 > 1){
			quicksort(a+i+1,n-i-1);
		}
	finish = clock();
    timequicksort = (double)(finish - start) / CLOCKS_PER_SEC;

}

#include <stdio.h>
#include <stdlib.h>


void swap(int *x,int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void SelectionSort(int *list,int n)
{
	int i,j;
	int minindex;
	int count = 0;
	for(i=0; i<n; i++){
		minindex = i;
		for(j=i; j<n; j++){
			if(list[minindex] > list[j])
				minindex = j;
		}
		if(minindex != i){
			swap(&list[i],&list[minindex]);
			count++;
		}
	}

	for(i=0; i<n; i++){
		printf("%d",list[i]);
		if(i != (n-1)){
			printf(" ");
		}
	}
	printf("\n%d\n",count);
}

int main()
{
	int n;
	scanf("%d",&n);

	int *list = malloc(n*sizeof(int));

	int i;
	for(i=0; i<n; i++){
		scanf("%d",&list[i]);
	}

	SelectionSort(list,n);

	return(0);
}

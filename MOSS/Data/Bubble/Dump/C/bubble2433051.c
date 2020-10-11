#include <stdio.h>
#include <stdlib.h>

void
swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void
bsort(int *list,int n)
{
	int i,j;
	int count = 0;
	for(i=0; i<n; i++){
		for(j=n-1; i<j; j--){
			if(list[j-1] > list[j]){
				swap(&list[j-1],&list[j]);
				count++;
			}
		}
	}
	for(i=0; i<n; i++){
		printf("%d",list[i]);
		if(i != (n-1)){
      printf(" ");
    }
	}
	
	printf("\n%d\n", count);

}


int
main()
{
	int n;
	scanf("%d",&n);

	int *list = (int *)malloc(n * sizeof(int));
	
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &list[i]);
	}
	bsort(list,n);
	return 0;
}

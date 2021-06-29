#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, i, j, minj, temp, count=0;
	int *a;
	scanf("%d", &n);
	a = malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	for(i=0;i<n;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(a[j]<a[minj]){
				minj=j;
			}
		}
		if(a[i]!=a[minj]){
			temp=a[i];
			a[i]=a[minj];
			a[minj]=temp;
			count++;
		}
	}
	printf("%d", a[0]);
	for(i=1;i<n;i++){
		printf(" %d", a[i]);
	}
	printf("\n");
	printf("%d\n", count);
}

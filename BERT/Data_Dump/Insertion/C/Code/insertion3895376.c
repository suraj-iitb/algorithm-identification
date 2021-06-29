#include<stdio.h>

int main(void){
	int n;
	int i, v,j;
	int last;
	int a[100];
	scanf("%d", &n);
	
	for(i =0;i<n;i++){
		scanf("%d", &a[i]);
	}
	
	for(i = 1;i<n;i++){
		for(last =0;last<n;last++){
			printf("%d", a[last]);
		if(last != n-1)
		printf(" ");
		}
		printf("\n");
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1] = a[j];
			j--;
		}
	a[j+1] = v;
	}
	for(last =0;last<n;last++){
			printf("%d", a[last]);
		if(last != n-1)
		printf(" ");
		}
	printf("\n");
	return 0;
}


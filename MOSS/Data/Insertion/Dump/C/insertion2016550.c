#include <stdio.h>

void isort(int n, int a[]){
	int i,j,k,v;
	for(i = 0; i <= n-1; i++){
		v = a[i];
		j = i-1;
		while(j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		for(k = 0; k < n; k++){
			printf("%d",a[k]);
			if(k != n-1)
				printf(" ");
		}
		//printf("a");
		//printf("\n");
		if(i != n-1)
			printf("\n");
	}
	printf("\n");
}

int main(){
	int n,i;
	int a[100];
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	isort(n,a);
	return 0;
}

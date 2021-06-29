#include<stdio.h>

int main(void){
	
	int n,v,j;
	
	scanf("%d", &n);
	int a[n];
	
	
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		printf("%d", a[i]);
		if(i!=n-1)printf(" ");
	}
		printf("\n");
	
	
	for(int i = 1;i < n;i++){
		v = a[i];
		j = i-1;
	while(j >= 0 && a[j] > v){
		a[j+1] = a[j];
		j--;
		a[j+1] = v;
	}
		for(int i = 0;i < n;i++){
			printf("%d", a[i]);
			if(i!=n-1)printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}

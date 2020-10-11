#include<stdio.h>

int main(void){
	
	int n,w[100],i,j,s,count,min;
	count=0;
	min=100;
	
	scanf("%d",&n);
	
	for(i=0; i<n; i++){
		scanf("%d",&w[i]);
	}
	
	for(j=0; j<n-1; j++){
		for(i=j; i<n; i++){
			if(w[i] < min){
				min = w[i];
				s=i;
			}
		}
		
		if(s != j){
			w[s]=w[j];
			w[j]=min;
			count++;
		}
		min = 100;
	}
	
	for(i=0; i<n; i++){
		printf("%d",w[i]);
		if(i != n-1){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",count);
	
	return 0;
}
	

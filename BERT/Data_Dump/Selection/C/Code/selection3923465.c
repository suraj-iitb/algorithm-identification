#include <stdio.h>

int main(void){
	int c,i,j,n,A[100],min,flag;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	flag=0;
	
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(A[j]<A[min]){
				min=j;
			}
		}
		c=A[i];
		A[i]=A[min];
		A[min]=c;
		if(A[min]!=A[i]){
			flag++;
		}
	}
	
	for(i=0;i<n;i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",A[i]);
		if(i==n-1){
			printf("\n%d\n",flag);
		}
	}
	
	return 0;
}

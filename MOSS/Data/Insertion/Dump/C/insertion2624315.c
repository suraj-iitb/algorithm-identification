#include <stdio.h>

void show(int A[],int n){
	int i;
	for(i=1;i<=n;i++){
		if(i>1)      
		printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
}
int main(void){
	int n,i,j,p;
	int A[100+1];
	scanf("%d",&n); 
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	show(A,n);
	for(j=2;j<=n;j++){
		p=A[j];
		i=j-1;
		while(i>0 && A[i]>p){
			A[i+1]=A[i];
			i--;
		}
		A[i+1]=p; 
		show(A,n); 
	}
	return 0;
}

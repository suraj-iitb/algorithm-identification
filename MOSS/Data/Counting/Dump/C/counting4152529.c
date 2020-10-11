#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
int main(){
	unsigned short *A,*B;
	int C[MAX+1];
	int n,i,j;
	scanf("%d",&n);
	A=malloc(sizeof(short)*n+1);
	B=malloc(sizeof(short)*n+1);
	 /*定义以及分配存储空间*/ 
	for(i=1;i<=n;i++){
		scanf("%hu",&A[i]);
	}
	for(i=0;i<=MAX;i++)
	C[i]=0;
	for(i=1;i<=n;i++)
		C[A[i]]++;
    for(i=1;i<=MAX;i++)
    C[i]=C[i]+C[i-1];
    for(i=n;i>0;i--){
    	B[C[A[i]]]=A[i];
    	C[A[i]]--;
	}//从A的末尾开始选择则稳定 
	for(i=1;i<=n;i++){
		if(i-1)
		printf(" ");
		printf("%d",B[i]);
	}
	printf("\n");
	return 0;
} 

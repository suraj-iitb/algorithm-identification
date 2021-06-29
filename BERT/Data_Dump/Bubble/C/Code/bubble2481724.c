#include <stdio.h>

#define MAX 101
void bubbleSort(int A[],int);

int main(void){
	int A[MAX],i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	bubbleSort(A,n);
	return 0;
}

void bubbleSort(int A[],int n){
	int i,j,a,tmp,count=0;
	
	for(i=0;i<n;i++){
		for(j=n-1;j>=i+1;j--){
			if(A[j]<A[j-1]){
				tmp=A[j];
				A[j]=A[j-1];
				A[j-1]=tmp;
				count++;
			}
		}
	}
	for(a=0;a<n;a++){
	printf("%d",A[a]);
	if(a!=n-1)printf(" ");
	}
	printf("\n%d\n",count);
}

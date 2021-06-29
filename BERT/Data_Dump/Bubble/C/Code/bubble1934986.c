#include<stdio.h>

int main (void)
{
	int i=0;
	int flag=1;
	int n,A[100];
	int j;
	int tmp;
	int cou=0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	while(flag){
		flag=0;
		for(j=n-1;j>=1;j--){
			if(A[j] < A[j-1]){
				tmp=A[j];
				A[j]=A[j-1];
				A[j-1]=tmp;
				cou++;
				flag=1;
			}
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n%d\n",A[n-1],cou);

	return 0;
}

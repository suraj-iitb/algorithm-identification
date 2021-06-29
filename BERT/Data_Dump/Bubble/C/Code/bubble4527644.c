#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int A[n];
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	int swap=0,sort;
	for(i=0;i<n;i++){
		for(j=1;j<n;j++){
			if(A[j-1]>A[j]){
				sort=A[j];
				A[j]=A[j-1];
				A[j-1]=sort;
				swap++;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d",A[i]);
		if(i+1!=n){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",swap);
	return 0;
}


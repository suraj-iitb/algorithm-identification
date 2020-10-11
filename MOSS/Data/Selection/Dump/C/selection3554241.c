#include<stdio.h>
int main(void){
	int A[100];
	int n,i,minj,j,a,t;
	int cout=0;
	scanf("%d\n",&n);
	for(t=0;t<n;t++){
		scanf("%d\n",&A[t]);
	}
	for(i=0;i<n;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		if(minj!=i&&A[i]>A[minj]){
			a=A[minj];
			A[minj]=A[i];
			A[i]=a;
			cout++;
		}
	}
	for(t=0;t<n;t++){
		if(t==n-1){
			printf("%d\n",A[t]);
		}else{
			printf("%d ",A[t]);
		}
	}
	printf("%d\n",cout);
	return 0;
}

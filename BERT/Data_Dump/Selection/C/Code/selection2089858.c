#include<stdio.h>
selectionSort(int *A,int N){
	int i,j,tmp,count=0,minj;
	for(i=0;i<N;i++){
		minj=i;
		for(j=i;j<=N-1;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		if(i!=minj){
			tmp=A[i];
			A[i]=A[minj];
			A[minj]=tmp;
			count++;
		}
	}
	return count;
}
int main(){
	int i,n,N[100],count;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&N[i]);
	}
	count=selectionSort(N,n);
	for(i=0;i<n-1;i++){
		printf("%d ",N[i]);
	}
	printf("%d\n",N[n-1]);
	printf("%d\n",count);
	return 0;
}

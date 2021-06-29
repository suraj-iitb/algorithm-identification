#include<iostream>
using namespace std;
int selectionSort(int A[],int N){
int minj,i,j,ans=0,node;
	for(i=0;i<N;i++){
	minj=i;
		for(j=i;j<N;j++){
			if(A[j]<A[minj]){
			minj=j;
			}
		}
				node=A[i];
				A[i]=A[minj];
				A[minj]=node;
				if(i!=minj)
				ans++;
	}
	return ans;
}

main(){
	int ans,n,i;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	ans=selectionSort(A,n);
	for(i=0;i<n;i++){
		if(i==n-1){
			printf("%d",A[i]);
			break;
		}
		printf("%d ",A[i]);
	}
	printf("\n%d\n",ans);
	return 0;
}


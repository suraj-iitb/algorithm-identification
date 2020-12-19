#include <cstdio>
using namespace std;

int n;

void CountingSort(int A[],int B[],int k){
	int C[k+1]={};
	
	for(int i=0;i<n;i++) C[A[i]]++;
	
	for(int i=1;i<=k;i++) C[i]+=C[i-1];
	
	for(int i=n-1;i>=0;i--){
		B[C[A[i]]-1]=A[i];
		C[A[i]]--;
	}
}

int main(){
	scanf("%d",&n);
	int A[n],B[n];
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	
	CountingSort(A,B,10000);
	
	for(int i=0;i<n;i++){
		if(i) printf(" ");
		printf("%d",B[i]);
	}
	printf("\n");
	
	return 0;
}


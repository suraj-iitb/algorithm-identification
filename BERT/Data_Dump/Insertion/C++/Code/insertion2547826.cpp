#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int N,A[100],v;
	int j;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	printf("%d",A[0]);
	for(int i=1;i<N;i++){
		printf(" %d",A[i]);
	}
	printf("\n");
	for(int i=1;i<N;i++){
		v=A[i];
		j=i-1;
		while(j>=0&&A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		printf("%d",A[0]);
		for(int k=1;k<N;k++){
			printf(" %d",A[k]);
		}
		printf("\n");
	}
}

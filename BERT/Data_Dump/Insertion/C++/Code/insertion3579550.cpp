#include<stdio.h>
using namespace std;
void trace(int A[],int N){
	for(int i=0;i<N;++i){
		if(i>0) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
}
void insertionSort(int A[],int N){
	int i,prev_pos;
	for(int i=1;i<N;i++){
		int prev_pos = i-1;
		int temp_val = A[i];
		while(prev_pos >= 0 && A[prev_pos] > temp_val){
			A[prev_pos+1] = A[prev_pos];
			prev_pos--;
		}
		A[prev_pos+1] = temp_val;
		trace(A,N);
	}
}
int main(){
	int N;
	int A[100];
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	trace(A,N);
	insertionSort(A,N);
	return 0;
}

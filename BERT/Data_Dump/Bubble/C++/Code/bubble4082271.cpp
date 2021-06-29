#include <iostream>
#include <stdio.h>
using namespace std;

int BubbleSort(int A[],int N){
	int rs = 0;
	bool flag = true;
	for(int i = 0; flag; i++){
		flag = false;
		for (int j= N-1; j>=i+1; j--){
			if(A[j] < A[j-1]){
				swap(A[j],A[j-1]);
				flag = true;
				rs++;
			}
		}
	}
	return rs;
}

int main(){
	int A[100],N,rs;
	scanf("%d",&N);
	for(int i = 0; i<N;i++){
		scanf("%d", &A[i]);
	}
	rs = BubbleSort(A,N);
	for(int i = 0; i<N;i++){
		if(i) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n",rs);
	return 0;
}

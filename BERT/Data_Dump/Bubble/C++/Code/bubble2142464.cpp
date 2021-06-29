#include <iostream>
#include <stdio.h>
static int MAX = 100;

void bubbleSort(int *A,int N){
	int flag=1;
	int buf;
	int count=0;
	while(flag){
		flag = 0;
		for(int i = N-1;i >= 1;i--){
			if(A[i] < A[i-1]){
				buf = A[i];
				A[i] = A[i-1];
				A[i-1] = buf;
				flag = 1;
				count++;
			}
		}
	}
	printf("%d",A[0]);
	for(int i = 1;i < N;i++){
		printf(" %d",A[i]);
	}
	printf("\n");
	std::cout << count << std::endl;
}
int main(){
	int A[MAX];
	int n;
	std::cin >> n;
	for(int i = 0;i < n;i++) std::cin >> A[i];

	bubbleSort(A,n);


	return 0;
}

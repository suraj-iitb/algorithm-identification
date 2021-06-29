#include <iostream>
static int MAX = 100;

void insertionSort(int *A,int N){
	int i,j;
	int v;
	std::cout << A[0];
	for(j = 1;j < N;j++){ 
		std::cout << " ";
		std::cout << A[j];
	}
	std::cout << std::endl;
	for (i = 1; i < N; i++) {
		v = A[i];
		j = i-1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		std::cout << A[0];
		for(j = 1;j < N;j++){ 
			std::cout << " ";
			std::cout << A[j];
		}
		std::cout << std::endl;
	}
}
int main(){
	int A[MAX];
	int n;
	std::cin >> n;
	for(int i = 0;i < n;i++) std::cin >> A[i];

	insertionSort(A,n);

	return 0;
}

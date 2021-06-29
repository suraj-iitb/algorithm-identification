// ALDS_1_1_A Insertion Sort

#include <iostream>
#define NMAX	100

void outArray(int *array, int n){
	for(int i=0 ; i<n-1 ; i++){
		std::cout << array[i] << " ";
	}
	std::cout << array[n-1] << std::endl;

	return;
}

int main(int argc, char *argv[]){
	int N;
	int A[NMAX];

	std::cin >> N;
	for(int i=0 ; i<N ; i++){
		std::cin >> A[i];
	}

	for(int i=1 ; i<N ; i++){
		outArray(A, N);
		int target = A[i];
		int j = i;
		while( (j > 0) && (target < A[j-1]) ){
			A[j] = A[j-1];
			j--;
		}
		A[j] = target;
	}
	outArray(A, N);

	return 0;
}



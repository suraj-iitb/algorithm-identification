// ALDS_1_2_A Bubble Sort

#include <iostream>
#define NMAX	100

void swap(int *array, int a, int b){
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;

	return;
}

int main(int argc, char *argv[]){
	int N;
	int A[NMAX];
	int swap_cnt = 0;

	std::cin >> N;
	for(int i=0 ; i<N ; i++){
		std::cin >> A[i];
	}

	bool is_sorted = false;
	for(int j=0 ; (j<=N-1)&&(!is_sorted) ; j++){
		is_sorted = true;
		for(int i=N-1 ; i>j ; i--){
			if(A[i] < A[i-1]){
				is_sorted = false;
				swap(A, i, i-1);
				swap_cnt++;
			}
		}
	}

	for(int i=0 ; i<N-1 ; i++){
		std::cout << A[i] << " ";
	}
	std::cout << A[N-1] << std::endl;
	std::cout << swap_cnt << std::endl;

	return 0;
}


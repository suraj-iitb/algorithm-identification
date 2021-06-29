// ALDS_1_2_B Selection Sort

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

	for(int i=0 ; i<N ; i++){
		int jmin = i;
		for(int j=i+1 ; j<N ; j++){
			if(A[jmin] > A[j]){
				jmin = j;
			}
		}
		if(jmin != i){
			swap(A, jmin, i);
			swap_cnt++;
		}
	}

	for(int i=0 ; i<N-1 ; i++){
		std::cout << A[i] << " ";
	}
	std::cout << A[N-1] << std::endl;
	std::cout << swap_cnt << std::endl;

	return 0;
}


#include <iostream>

class Selection{
public:
	void trace(int *A, int N){
		for(int i = 0; i < N; i++){
			if(i > 0) std::cout << " ";
			std::cout << A[i];
		}
		std::cout << std::endl;
	}
	int selection_sort(int *A, int N){
		int count = 0;
		for(int i = 0; i < N; i++){
			int minj = i;
			for(int j = i; j < N; j++){
				if(A[j] < A[minj]){
					minj = j;
				}
			}
			if(i != minj){
				int tmp = A[i];
				A[i] = A[minj];
				A[minj] = tmp;
				++count;
			}
		}
		trace(A, N);
		return count;
	}

};

int main(){
	Selection s;
	int N;
	int A[100];

	std::cin >> N;
	for(int i = 0; i < N; i++){
		std::cin >> A[i];
	}
	std::cout << s.selection_sort(A, N) << std::endl;
}

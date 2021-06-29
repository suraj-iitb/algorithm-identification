#include<iostream>

class Select{
	int count = 0;
public:
	void trace(int *A, int N){
		for(int i = 0; i < N; ++i){
			if(i > 0) std::cout << " ";
			std::cout << A[i];
		}
		std::cout << std::endl;
		return;
	}
	void select_sort(int *A, int N){
		for(int i = 0; i < N - 1; ++i){
			int minj = i;
			for(int j = i+1; j < N; ++j){
				if(A[minj] > A[j]){
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
		std::cout << count << std::endl;
		return;
	}
};

int main(){
	Select s;
	int A[100];
	int N;

	std::cin >> N;
	for(int i = 0; i < N; ++i){
		std::cin >> A[i];
	}
	s.select_sort(A, N);

	return 0;
}

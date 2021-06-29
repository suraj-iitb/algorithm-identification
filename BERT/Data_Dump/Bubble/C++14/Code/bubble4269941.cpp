#include <iostream>

class Bubble{
	int count = 0;
public:
	void bubble_sort(int *A, int N){
		int flag = 1;
		while(flag){
			flag = 0;
			for(int i = N-1; i > 0; --i){
				if(A[i] < A[i-1]){
					int tmp = A[i-1];
					A[i-1] = A[i];
					A[i] = tmp;
					flag = 1;
					++count;
				}
			}
		}
		for(int i = 0; i < N; ++i){
			if(i > 0) std::cout << " ";
			std::cout << A[i];
		}
		std::cout << std::endl;
		std::cout << count << std::endl;
		return;
	}
};

int main(){
	Bubble bub;
	int A[100];
	int N;

	std::cin >> N;

	for(int i = 0; i < N; ++i){
		std::cin >> A[i];
	}
	bub.bubble_sort(A, N);
	return 0;
}

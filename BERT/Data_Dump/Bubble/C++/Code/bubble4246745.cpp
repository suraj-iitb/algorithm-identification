#include <iostream>

#define MAX 100

class Bubble{
public:
	void trace(int *A, int N){
		for(int i = 0; i < N; i++){
			if(i > 0) std::cout << " ";
			std::cout << A[i];
		}
		std::cout << std::endl;
	}

	void bubble_sort(int *A, int N){
		int flag = 1;
		int count = 0;
		int i = 0;
		while(flag){
			flag = 0;
			for(int j = N-1; j >= i+1; --j){
				if(A[j] < A[j-1]){
					int tmp = A[j];
					A[j] = A[j-1];
					A[j-1] = tmp;
					flag = 1;
					++count;
				}
			}
			++i;
		}
		trace(A, N);
		std::cout << count << std::endl;
	}

};

int main(){
	Bubble bubble;
	int itr;
	int A[MAX];
	std::cin >> itr;
	for(int i = 0; i < itr; i++){
		std::cin >> A[i];
	}
	bubble.bubble_sort(A, itr);
	return 0;
}

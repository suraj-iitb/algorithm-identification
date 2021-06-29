#include<iostream>
#include<vector>
int main(void) {
	int N;
	std::cin >> N;
	std::vector<int>A(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
	}
	int NumberChange = 0;
	for (int i=0; i < N; ++i) {
		int Minj = i;
		for (int j = i+1; j< N; ++j) {
			if (A[j] < A[Minj]) { Minj = j;
				}
			
		}if (Minj != i) {
			std::swap(A[i], A[Minj]);
			++NumberChange;
		}
	}
		for (int i = 0; i < N ; ++i) {
		if(i==N-1){ std::cout << A[i] << std::endl; }
		else { std::cout << A[i] << " "; }
	}
	std::cout  << NumberChange << std::endl;
	//system("pause");
	return 0;
}

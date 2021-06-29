#include <iostream>

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int N;
	std::cin >> N;
	
	int *A = new int[N];
	for (int i=0; i<N; i++) std::cin >> A[i];
	
	int swap_count = 0;
	for (int i=0; i<N; i++) {
		for (int j=N-1; j>i; j--) {
			if (A[j-1] > A[j]) {
				swap(A[j-1], A[j]); swap_count++;
			}
		}
	}
	
	std::cout << A[0];
	for (int i=1; i<N; i++) std::cout << " " << A[i];
	std::cout << std::endl;
	std::cout << swap_count << std::endl;
	
	delete[] A;
	
	return 0;
}



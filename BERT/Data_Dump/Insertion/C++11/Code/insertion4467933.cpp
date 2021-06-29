#include <iostream>

void show(int *A, int N)
{
	std::cout << A[0];
	for (int i=1; i<N; i++) {
		std::cout << " " << A[i];
	}
	std::cout << std::endl;
}

int main()
{
	int N;
	std::cin >> N;
	
	int *A = new int[N];
	for (int i=0; i<N; i++) std::cin >> A[i];
	
	show(A, N);
	
	for (int i=1; i<N; i++) {
		int key = A[i];
		int j;
		for (j=i-1; j>=0 && A[j] > key; j--) {
			A[j+1] = A[j];
		}
		A[j+1] = key;
		show(A, N);
	}
	
	delete[] A;
	
	return 0;
}



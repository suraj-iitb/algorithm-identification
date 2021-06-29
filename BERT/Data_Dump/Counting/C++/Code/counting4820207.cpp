#include <iostream>

#define N_MAX 2000000
#define V_MAX 10000

unsigned short *A, *B;
int N;

int C[V_MAX + 1];

int main()
{
	std::fill(C, C + V_MAX + 1, 0);
	
	std::cin >> N;
	A = new unsigned short[N];
	B = new unsigned short[N];
	
	for(int i = 0; i < N; ++i)
	{
		std::cin >> A[i];
		C[A[i]]++;
	}
	
	for( int i = 1; i <= V_MAX; ++i ) C[i] = C[i] + C[i - 1];
	
	for(int i = 0; i < N; ++i)
	{
		B[--C[A[i]]] = A[i];
	}
	
	for(int i = 0; i < N; ++i)
	{
		if(i > 0) std::cout << ' ';
		std::cout << B[i];
	}
	std::cout << std::endl;
	
	delete[] A;
	delete[] B;
	return 0;
}

 

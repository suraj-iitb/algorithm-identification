#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	int n;
	std::cin >> n;
	
	std::vector<int> A(n + 1), B(n + 1, 0), C(10001, 0);
	
	for(int i = 0; i < n; ++i)
	{
		std::cin >> A[i + 1];
		C[A[i + 1]]++;
	}
	
	for(int i = 1; i <= 10000; ++i)
	{
		C[i] += C[i - 1];
	}
	
	for(int j = n; j >= 1; j--)
	{
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
	
	for(int i = 1; i <= n; ++i)
	{
		if( i > 1 ) std::cout << " ";
		std::cout << B[i];
	}
	
	std::cout << std::endl;
	
	return 0;
}


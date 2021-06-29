#include <iostream>

#define MAX_N 100

int N;
int A[MAX_N + 1];

void print()
{
	for(int i = 0; i < N; ++i)
	{
		if(i == 0) std::cout << A[i];
		else std::cout << ' ' << A[i]; 
	} 
	
	std::cout << '\n';
}

void solve()
{
	for(int i = 1; i < N; i++)
	{
		int j = i - 1;
		int key = A[i];
		
		while(j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j--;	
		} 
		
		A[j + 1] = key;
		
		print();
	}
}

int main()
{
	std::cin >> N;
	
	for(int i = 0; i < N; ++i) std::cin >> A[i];
	
	print();
	solve(); 
	
	return 0;
}


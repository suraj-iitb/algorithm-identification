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

int solve()
{
	int cnt = 0;
	for(int i = 0; i < N; ++i)
	{
		int minj = i; 
		for(int j = i + 1; j < N; ++j)
		{
			if(A[j] < A[minj])
			{
				minj = j;
			}
		} 
		
		if(i != minj)
			++cnt;
		std::swap(A[i], A[minj]);
	}
	
	return cnt;
}

int main()
{
	std::cin >> N;
	
	for(int i = 0; i < N; ++i) std::cin >> A[i];
	
	int cnt = solve();
	
	print();
	
	std::cout << cnt << std::endl;
	
	return 0;
}
 

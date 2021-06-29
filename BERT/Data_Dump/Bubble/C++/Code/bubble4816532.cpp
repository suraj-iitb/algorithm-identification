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

int solve1()
{
	int cnt = 0;
	for(int i = 0; i < N; ++i)
	{
		
		for(int j = N-1; j > i; --j)
		{
			
			if(A[j] < A[j - 1])
			{
				std::swap(A[j], A[j - 1]);
				++cnt;
			}
			
		}
		
	}
	return cnt;
}


int solve2()
{
	int cnt = 0;
	bool flag = true;
	
	for(int i = 0; flag; ++i)
	{
		flag = false;
		
		
		for(int j = N - 1; j > i; --j)
		{
			
			if(A[j] < A[j - 1])
			{
				std::swap(A[j], A[j - 1]);
				++cnt;
				flag = true;
			}
			
		}
		
	}
	
	return cnt;
}

int main()
{
	std::cin >> N;
	
	for(int i = 0; i < N; ++i) std::cin >> A[i];
	
	int cnt = solve2();
	
	print();
	
	std::cout << cnt << std::endl;
	
	return 0;
}
 

#include <iostream>

#define MAX_N 500001
#define SENTINEL 2000000000

int A[MAX_N];

int L[MAX_N / 2 + 2], R[MAX_N / 2 + 2];

int N;
int cnt = 0;

void merge(int beg, int end, int mid)
{
	
	int n1 = mid - beg;
	int n2 = end - mid;
	
	for(int i = 0; i < n1; ++i) L[i] = A[beg + i];
	for(int i = 0; i < n2; ++i) R[i] = A[mid + i];
	
	L[n1] = SENTINEL;
	R[n2] = SENTINEL;
	
	int i = 0, j = 0;
	
	for(int k = beg; k < end; ++k)
	{
		cnt++;
		
		if(L[i] <= R[j])
		{
			A[k] = L[i++];
		}
		else
		{
			A[k] = R[j++];
		}
		
	}
	
}

void solve(int beg, int end)
{
	
	if(end - beg > 1)
	{
		
		int m = beg + ((end - beg)>>1);
		
		solve(beg, m);
		solve(m, end);
		
		merge(beg, end, m);
		
	}
	
}

int main()
{
	std::cin >> N;
	for(int i = 0; i < N; ++i) std::cin >> A[i];
	solve(0, N);
	
	for(int i = 0; i < N; ++i)
	{
		if(i > 0) std::cout << ' ';
		std::cout << A[i];
	}
	
	std::cout << '\n' << cnt << std::endl;
	
	return 0;
}
 

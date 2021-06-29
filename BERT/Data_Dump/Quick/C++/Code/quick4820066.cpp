

#include <iostream>

#define MAX_N 100000

struct card
{
	char ch;
	int num;
};

card A[MAX_N + 1];
card C[MAX_N + 1];
card H[MAX_N + 1];

int N;

int Partition(int p, int r)
{
	
	int x = A[r].num;
	int i = p;
	
	for(int j = p; j < r; ++j)
	{
		if(A[j].num <= x)
		{
			std::swap(A[i++], A[j]);
		}
	}
	std::swap(A[i], A[r]);
	return i;
}

void QuickSort(int p, int r)
{
	
	if(r > p)
	{
		int m = Partition(p, r);
		QuickSort(p, m - 1);
		QuickSort(m + 1, r);
	}
	
} 

void Merge(int beg, int mid, int end)
{
	std::copy(C + beg, C + end, H + beg);
	
	int left = beg;
	int right = mid;
	int j = beg;
	while( left < mid && right < end )
	{
		if(H[left].num <= H[right].num)
		{
			C[j++] = H[left++];
		}
		else
		{
			C[j++] = H[right++];
		}
	}
	
	while(left < mid)
	{
		C[j++] = H[left++];
	}
}

void MergeSort(int beg, int end)
{
	if(end - beg > 1)
	{
		int mid = beg + ((end - beg) >> 1);
		
		MergeSort(beg, mid);
		MergeSort(mid, end);
		
		Merge(beg, mid, end);
	}
}

bool stable()
{
	
	for(int i = 0; i < N; ++i)
	{
		if(C[i].ch != A[i].ch) return false;
	}
	return true;
}

int main()
{
	std::cin >> N;
	for(int i = 0; i < N; ++i) 
	{
		std::cin >> A[i].ch >> A[i].num;
		C[i] = A[i];
	}
	
	QuickSort(0, N - 1);
	MergeSort(0, N);
	
	std::cout << (stable()?"Stable":"Not stable") << std::endl;
	
	for(int i = 0; i < N; ++i)
	{
		std::cout << A[i].ch << ' ' << A[i].num /*<< ' ' << C[i].ch << ' ' << C[i].num*/ << std::endl;
	}
	
	
	return 0;
}


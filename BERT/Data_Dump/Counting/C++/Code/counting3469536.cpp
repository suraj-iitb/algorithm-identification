#include <iostream>
#include <vector>
using namespace std;

int C[100005];

void CountingSort(vector<int> &A, vector<int> &B, int k)
{
	for(int i = 0; i <= k; ++i)
	{
		C[i] = 0;
	}
	
	for(int j = 0; j < A.size(); ++j)
	{
		++C[A[j]];
	}

	for(int i = 1; i <= k; ++i)
	{
		C[i] += C[i - 1];
	}
	
	for(int j = A.size() - 1; j >= 0; --j)
	{
		
		--C[A[j]];
		B[C[A[j]]] = A[j];
	}
}

int main()
{
	int N, temp, max = 0;
	vector<int> A, B;
	
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> temp;
		A.push_back(temp);
		B.push_back(temp);
		
		if(temp > max)
		{
			max = temp;
		}
	}
	
	CountingSort(A, B, max);
	
	for(int i = 0; i < B.size(); ++i)
	{
		if(i != 0)
		{
			cout << " ";
		}
		
		cout << B[i];
	}
	cout << endl;

    return 0;
}


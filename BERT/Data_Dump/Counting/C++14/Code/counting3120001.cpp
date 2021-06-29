#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define MAX_N 2000000
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> vec(MAX_N+10);
	vector<int> A(MAX_N+10, 0);
	int idx = 0;
	rep(i, n)
	{
		cin >> vec[i];
		A[vec[i]]++;
	}
	for(int i=1; i<10000; i++)
	{
		A[i] += A[i-1];
		if(A[i] > idx) idx = A[i];
	}
	//rep(i,15) cout << A[i] << " ";
	//cout << endl;
	vector<int> B(idx+1, 0);
	for(int i=0; i<=idx; i++)
	{
		B[A[vec[i]]] = vec[i];
		A[vec[i]]--;
	}
	for(int i=1; i<=idx; i++)	
	{
		if(i == 1) cout << B[i];
		else cout << " " << B[i];
	}
	cout << endl;
	return 0;
}


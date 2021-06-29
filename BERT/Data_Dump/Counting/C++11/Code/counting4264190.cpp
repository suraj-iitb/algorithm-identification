#include<iostream>

using namespace std;

int A[2000000];
int B[2000000];
int C[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0; i<n; i++) cin>>A[i];

	for(int i=0; i<n; i++) C[A[i]]++;
	C[0]--;
	for(int i=1; i<=10000; i++) C[i]+=C[i-1];
	for(int i=n-1; i>=0; i--) {
		B[C[A[i]]]=A[i];
		C[A[i]]--;
	}

	cout<<B[0];
	for(int i=1; i<n; i++) cout<<' '<<B[i];
	cout<<'\n';

	return 0;
}


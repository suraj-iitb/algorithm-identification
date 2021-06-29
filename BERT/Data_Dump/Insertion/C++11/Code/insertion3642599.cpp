#include<iostream>

using namespace std;

void insertionSort(int *A, int n) {
	for(int i=1; i<n; i++) {
		int v=A[i];
		int j=i-1;
		while(j>=0 && A[j]>v) {
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		cout<<A[0];
		for(int k=1; k<n; k++) cout<<' '<<A[k];
		cout<<'\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, A[1000];
	cin>>n;
	for(int i=0; i<n; i++) cin>>A[i];
	cout<<A[0];
	for(int i=1; i<n; i++) cout<<' '<<A[i];
	cout<<'\n';
	insertionSort(A, n);
	return 0;
}


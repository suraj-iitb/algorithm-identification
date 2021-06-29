#include<iostream>
#include<utility>

using namespace std;

int selectionSort(int *A, int n) {
	int count=0;
	for(int i=0; i<n; i++) {
		int minj = i;
		for(int j=i+1; j<n; j++) {
			if(A[j] < A[minj]) minj=j;
		}
		if(i!=minj) {
			swap(A[i], A[minj]);
			count++;
		}
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, A[100];
	cin>>n;
	for(int i=0; i<n; i++) cin>>A[i];
	int count = selectionSort(A, n);
	cout<<A[0];
	for(int i=1; i<n; i++) cout<<' '<<A[i];
	cout<<'\n'<<count<<'\n';
	return 0;
}


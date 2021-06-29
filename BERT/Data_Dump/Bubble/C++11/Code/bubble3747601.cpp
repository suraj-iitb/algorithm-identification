#include<iostream>
#include<utility>

using namespace std;

int bubbleSort(int *A, int n) {
	bool flag = true;
	int count=0;
	while(flag) {
		flag=false;
		for(int j=n-1; j>0; j--) {
			if(A[j]<A[j-1]) {
				swap(A[j], A[j-1]);
				flag=true;
				count++;
			}
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
	int count = bubbleSort(A, n);
	cout<<A[0];
	for(int i=1; i<n; i++) cout<<' '<<A[i];
	cout<<'\n'<<count<<'\n';
	return 0;
}


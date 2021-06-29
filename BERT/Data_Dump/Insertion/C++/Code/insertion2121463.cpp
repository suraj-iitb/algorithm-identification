#include <iostream>
using namespace std;

int main() {
	int N, i, s; 
	cin >> N;
	int A[N];
	
	for (i=0; i<N; i++)
		cin >> A[i];

	for (s=0; s<N-1; s++)
		cout<<A[s]<<" ";
	cout<<A[N-1]<<'\n';

	for (i=1; i<=N-1; i++) {
		int j, v;
		v=A[i];
		j=i-1;
		while (j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		
		for (s=0; s<N-1; s++)
		cout<<A[s]<<" ";
		
		cout<<A[N-1]<<'\n';
	}
	
	
	// your code goes here
	return 0;
}

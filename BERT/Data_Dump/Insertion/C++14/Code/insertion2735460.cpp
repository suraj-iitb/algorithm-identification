#include <iostream>
using namespace std;

#define is_uruu main
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
	
int is_uruu() {
	int N;
	cin >> N;
	int A[N];
	FOR(i,0,N)cin >> A[i];
	FOR(i,0,N-1)cout << A[i] << " ";
	cout << A[N-1] << endl;
	
	FOR(i,1,N){
		int v=A[i];
		int j=i-1;
		while(A[j]>v && j>=0){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		FOR(i,0,N-1)cout << A[i] << " ";
		cout << A[N-1] << endl;
	}
	
	return 0;
}

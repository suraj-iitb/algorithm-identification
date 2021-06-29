#include <bits/stdc++.h>
using namespace std;

#define is_uruu leapyear
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(a);i>(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

int n, C[2000000]={0};

void countSort(int A[], int B[], int k){
	
	FOR(i, 0, n){
		C[A[i]]++;
	}
	FOR(i, 1, k+1){
		C[i] += C[i-1];
	}
	ROF(i, n-1, -1){
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}
	
int main(){
	
	int A[2000000], B[2000000];
	cin >> n;
	FOR(i, 0, n){
		cin >> A[i];
	}
	
	countSort(A, B, 10000);
	
	FOR(i, 1, n) cout << B[i] << " ";
	cout << B[n] << endl;
	
	return 0;
}

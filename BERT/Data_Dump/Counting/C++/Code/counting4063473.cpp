#include<bits/stdc++.h>
#define N 2000001
#define MAX 10000
using namespace std;
int n=0;
vector<int> A(N,0),B(N,0),C(N,0);

void CountingSort(){
	//for(int i=0;i<MAX;i++) C.at(i) = 0;
	
	/* C[i] に i の出現数を記録する */
	//for(int j=1;j<=n;j++) C.at(A.at(j))++;
	
	/* C[i] に i 以下の数の出現数を記録する*/
	for(int i=1;i<MAX;i++) C.at(i) += C.at(i-1);
	
	for(int j=1;j<=n;j++){
		/*(int j=n;j>0;j--)*/
		B.at(C.at(A.at(j))) = A.at(j);
		C.at(A.at(j))--;
	}
	for(int i=1;i<=n;i++){
		if(i == n) cout << B.at(i) << endl;
		else cout << B.at(i) << " ";
	}
}

int main(){
	cin >> n;
	for(int i=0;i<MAX;i++) C.at(i) = 0;
	for(int i=0;i<n;i++){
		cin >> A.at(i+1);
		/* C[i] に i の出現数を記録する */
		C.at(A.at(i+1))++;
	}
	CountingSort();
}

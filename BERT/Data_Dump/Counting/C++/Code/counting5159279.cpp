#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAX 2000000
#define VMAX 10001


int main(){
	int n; cin >> n;
	int A[MAX], B[MAX];
	int k=VMAX;
	int C[VMAX];

	for(int i=0; i<n; i++) cin >> A[i];
	for(int i=0; i<k; i++) C[i]=0;

     /* C[i] に i の出現数を記録する */
     for(int j=0; j<n; j++) C[A[j]]++;

     /* C[i] に i 以下の数の出現数を記録する*/
    for(int i=1; i<=k; i++) C[i] = C[i] + C[i-1];

    for(int j=n-1; j >= 0; j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
	}

	for(int i=1; i<=n; i++){
		if(i>1) cout << " ";
		cout << B[i];
	}
	cout << endl;
}

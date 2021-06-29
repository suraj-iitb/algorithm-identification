#include <iostream>
/*
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <iomanip>
#include <numeric>
*/

using namespace std;

typedef long long LL;

void insertionSort(int A[], int N){

   int v,j,k;

   for (int i=1 ; i<N;i++){

	 v = A[i];
	 j = i - 1;
	 while (j >= 0 && A[j] > v){
	   A[j+1] = A[j];
	   j--;
	 }
	 A[j+1] = v;

	 for(k=0;k<N;k++){
		cout << A[k] << ((k == N-1) ? "\n" : " " );
	 }

   }
}

int main(int argc, const char * argv[]) {

	cin.tie(0);
	ios::sync_with_stdio(false);



	int N,i;
	int X[100];

	cin >> N;

	for(i=0;i<N;i++){
		cin >> X[i];
	}

	for(i=0;i<N;i++){
		cout << X[i] << ((i == N-1) ? "\n" : " " );
	}

	insertionSort(X,N);

	return 0;
}

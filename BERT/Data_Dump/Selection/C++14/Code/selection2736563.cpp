#include <iostream>
using namespace std;

#define is_uruu main
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(a);i>(b);--i)
    
int selectionSort(int A[],int N){
	int count=0;
	FOR(i,0,N-1){
		int minj=i;
		FOR(j,i+1,N){
			if(A[minj] > A[j])minj = j;
		}
		if(minj != i){
			swap(A[i], A[minj]);
			count++;
		}
	}
    return count;
}
    
int is_uruu(){
	int N, count, A[100];
	cin >> N;
	FOR(i,0,N)cin >> A[i];
	
	count = selectionSort(A, N);
	
	FOR(i,0,N-1)cout << A[i] << " ";
	cout << A[N-1] << endl << count << endl;
	return 0;
}

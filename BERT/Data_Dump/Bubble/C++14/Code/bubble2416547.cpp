#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int N,int *A){
	int cnt=0;
	for(int i=0; i<N-1; i++){
		for(int j=N-1; j>i; j--){
			if(A[j-1]>A[j]){
				swap(A[j-1],A[j]);
				cnt++;
			}
		}
	}
	for(int i=0; i<N; i++)
		cout << A[i] << ((i<N-1)?" ":"");
	cout << endl;
	cout << cnt << endl;
}

int main(){
	int N; cin >> N;
	int array[N];
	for(int i=0;i<N;i++)
		cin >> array[i];
	BubbleSort(N,array);
	return 0;
}

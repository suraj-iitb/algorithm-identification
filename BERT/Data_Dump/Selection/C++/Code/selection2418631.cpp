#include <bits/stdc++.h>
using namespace std;

void selectionSort(int *A, int N){
	int cnt=0;
	for(int i=0; i<N; i++){
		bool flag = false;
		int minj = i;
		for(int j=i; j<N; j++){
			if(A[j]<A[minj]){
				minj = j;
				flag=true;
			}
		}
		if(flag==true){
			swap(A[i],A[minj]);
			cnt ++;
		}
	}
	for(int i=0; i<N; i++)
		cout << A[i] << (i<N-1?" ":"");
	cout << endl << cnt << endl;
}
int main(){
	int N; cin >> N;
	int array[N];
	for(int i=0; i<N; i++)
		cin >> array[i];
	selectionSort(array,N);
	return 0;
}

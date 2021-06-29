#include <iostream>

using namespace std;

void print(int[], int);

int main(){
//	BubbleSort(A)
//	1 for i = 0 to A.length-1
//	2     for j = A.length-1 downto i+1
//	3         if A[j] < A[j-1]
//	4             swap A[j] and A[j-1]
	int N, i, j, cnt = 0;
	cin >> N;
	int A[N];
	for(i = 0; i < N; i++){
		cin >> A[i];
	}
	for(i = 0; i < N; i++){
		for(j = N-1; j > i; j--){
			if(A[j] < A[j-1]){
				swap(A[j], A[j-1]);
				cnt++;
			}
		}
	}
	print(A, N);
	cout << cnt << endl;
	return 0;
}

void print(int A[], int N){
	cout << A[0];
	for(int k = 1; k < N; k++){
		cout << ' ' << A[k];
	}
	cout << endl;
}

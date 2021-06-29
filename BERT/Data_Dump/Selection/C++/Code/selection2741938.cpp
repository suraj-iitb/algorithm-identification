#include <iostream>

using namespace std;

void print(int[], int);

int main(){
//	SelectionSort(A)
//	1 for i = 0 to A.length-1
//	2     mini = i
//	3     for j = i to A.length-1
//	4         if A[j] < A[mini]
//	5             mini = j
//	6     swap A[i] and A[mini]
	int N, i, j, mini, cnt = 0;
	cin >> N;
	int A[N];
	for(i = 0; i < N; i++){
		cin >> A[i];
	}
	for(i = 0; i < N; i++){
		mini = i;
		for(j = i; j < N; j++){
			if(A[j] < A[mini]){
				mini = j;
			}
		}
		if(i != mini){
			swap(A[i], A[mini]);
			cnt++;
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

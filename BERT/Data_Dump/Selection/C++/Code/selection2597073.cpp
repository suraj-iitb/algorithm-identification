#include<iostream>
using namespace std;

int selectionSort(int A[], int N) {

	int count = 0, j, i , minj=0;
		for(i = 0; i < N-1; i++){
			minj = i;
			
		for (j = i; j <N; j++) {
		
			if (A[j] < A[minj]) 
				
				minj = j;
		
			
		}
			swap(A[i], A[minj]);
			if (i != minj)
			count++;
			
	
	}
	return count;
}
int main() {

	int A[100];
	int N, i, count;

	cin >> N;
	for (i = 0; i < N; i++)
		cin >> A[i];
	count = selectionSort(A, N);

	cout << A[0];
	for (i = 1; i < N; i++) cout <<" "<< A[i];
	cout << endl;
	cout << count << endl;


}

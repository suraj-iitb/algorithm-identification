#include <iostream>
using namespace std;

void show_array(int *array, int &N){

	for(int i=0; i<N; ++i){
		cout << array[i];
		if(i < N-1){
			cout << " ";
		}
	}	
	cout << endl;
}

int main(){
	int N;
	cin >> N;

	int A[N]; // define a static array

	// Input values in the array
	for(int i=0; i<N; i++){
   scanf("%d", &A[i]);
	}

	// Insertion Sort
	int v, j;
	show_array(A, N);
	for(int i=1; i<=N-1; ++i){
		v = A[i];
		j = i - 1;

		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j -= 1;
		}
		A[j+1] = v;

		// Show sorted values
		show_array(A, N);
	}

	return 0;
}

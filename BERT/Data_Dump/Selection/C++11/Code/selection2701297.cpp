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


	// Selection Sort
	int minj, temp; 
	int count = 0;
	for(int i= 0; i<N-1; ++i){
		minj = i;
		for(int j=i; j<=N-1; ++j){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(A[i] != A[minj]){
			count += 1;
			temp = A[minj];
			A[minj] = A[i];
			A[i] = temp;
		}
	}	

	show_array(A, N);
	cout << count << endl;

	return 0;

}

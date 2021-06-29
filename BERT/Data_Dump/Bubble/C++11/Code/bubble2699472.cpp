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

	// Bubble Sort
	int flag = 1;
	int temp;
	int count=0;
	while(flag){
		flag = 0;

		for(int j=N-1; 0<j; --j){
			if (A[j] < A[j-1]){
				temp = A[j-1];
				A[j-1] = A[j];
				A[j] = temp;

				count += 1;
				flag = 1;
			}
		}
	}

	show_array(A, N);
	cout << count << endl;


	return 0;
}

#include <iostream>
using namespace std;

void callarray(int array[], int N){
	for( int i = 0; i < N-1; i++ ){
		cout << array[i] << " " ;
	}
	cout << array[N-1] << endl;
}

void insertionsort(int array[], int N){
	int v, j;
	for( int i = 0; i < N; i++ ){
		v = array[i];
		j = i -1;
		while( j >= 0 && array[j] > v ){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = v;
		callarray(array, N);
	}
}




int main(){
	int N;
	cin >> N;
	
	int arr[N];
	for( int i = 0; i < N; i++ ){
		cin >> arr[i];
	}
	
	insertionsort(arr, N);
		
	return 0;
}


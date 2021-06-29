#include<iostream>
using namespace std;

void insertionSort(int array[], int N){

	for(int i=1; i<N; ++i){
		int v = array[i];
		int j = i - 1;
		while(j>=0 && array[j]>v){
			array[j+1] = array[j];
			--j;
		}
		array[j+1] = v; //array[-1] does not affect...
		for(int k=0; k<N; ++k){
			(k!=N-1) ? cout << array[k] << ' ' : cout << array[k];
		}
		cout << endl;
	}

}

int main(){
	int n;
	cin >> n;
	int array[n];

	for(int i=0; i<n; ++i){
		cin >> array[i];
		(i!=n-1) ? cout << array[i] << ' ' : cout << array[i];
	}
	cout << endl;
	insertionSort(array, n);

	return 0;
}


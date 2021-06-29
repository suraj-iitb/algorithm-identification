#include<iostream>
#include<cstdio>
using namespace std;

int A[100];


void trace( int[], int N){
	for(int i=0; i<N; i++){
		if( i>0 ) cout << " ";
		cout << A[i];
	}
	cout << "\n";
}


void Sort( int[], int N){
	int j,v;
	for(int i=1; i<N; i++){
		v = A[i];
		j = i-1;
		while( j>=0 && A[j]>v ){
			A[j+1] = A[j];
			j--;
		}

		A[j+1] = v;
		trace(A,N);
	}
}


int main(){
	int N;
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> A[i];
	}

	trace(A,N);
	Sort(A,N);

	return 0;
}

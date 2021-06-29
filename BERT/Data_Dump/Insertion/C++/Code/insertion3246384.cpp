#include<iostream>
using namespace std;

int N;

void out(int* arr){
	for(int i=0; i<N; i++) {
		cout << arr[i];
		if(i!=N-1) cout << " ";
	}
	cout << endl;
}

int main(){
	int v,j;
	cin >> N;
	int* A = new int[N];

	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	out(A);

//insertion sort
	for(int i=1;i<=N-1;i++){
		v=A[i];
		j=i-1;
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		out(A);
	}
	return 0;
}


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
	int minj, tmp, count=0;
	cin >> N;
	int* A = new int[N];

	for(int i=0;i<N;i++){
		cin >> A[i];
	}

//selection sort
	for(int i=0; i<N; i++){
	     minj = i;
	     for(int j=i; j<N; j++){
			 if(A[j]<A[minj]) {
				minj=j;
			 }
		 }
		 if(minj!=i) count++;
		 tmp=A[i];
		 A[i]=A[minj];
		 A[minj]=tmp;
	}
	out(A);
	cout << count << endl;

	return 0;
}


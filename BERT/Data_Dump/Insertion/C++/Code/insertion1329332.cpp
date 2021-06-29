#include <iostream>
#define    N    1001
using namespace std;

void insertionSort(int *A, int n){
	for(int i=0;i<n;i++){
		int v = A[i];
		int j = i-1;
		while((j >= 0) && (A[j] > v)){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		
	for(int k=0;k<n;k++){
		if(k!=0) cout<<" ";
		cout<<A[k];
	}
	cout<<endl;

	}
}

int main(){
	int n, A[N];

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}

	insertionSort(A, n);
	
	return 0;
}

#include <iostream>
using namespace std;

void outputArray(int A[],int n){
	for(int i=0;i<n-1;i++)
		cout<<A[i]<<" ";
	cout<<A[n-1]<<endl;
}

void insertionSort(int A[],int N){
	for(int i=0;i<N;i++){
		int v = A[i];
		int j = i-1;
		while(j>=0&&A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1] = v;

	outputArray(A,N);
	}
}

int main(){
	
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
		
	insertionSort(A, n);

//	outputArray(A,n);
	
	return 0;
}

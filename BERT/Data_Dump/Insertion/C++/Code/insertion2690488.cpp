#include <iostream>
using namespace std;

void printA(int A[],int n){
	for(int i=0;i<n-1;i++)
		cout<<A[i]<<" ";
	cout<<A[n-1]<<endl;
}

void  insertionSort(int A[],int n){
	for(int i=0;i<n;i++){
		int j=i,t;
		while(j>=1&&A[j]<A[j-1]){
			t=A[j];
			A[j]=A[j-1];
			A[j-1]=t;
			j--;
		}
		printA(A,n);
	}
}

int main(){
	int n;
	cin>>n;
	int A[100];
	for(int i=0;i<n;i++)
		cin>>A[i];
	insertionSort(A,n);
	return 0;
}

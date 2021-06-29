#include <iostream>
using namespace std;

int selectionSort(int A[],int n){

	int sw=0,t,minX;
	for(int i=0;i<n-1;i++){
	    minX=i;               
		for(int j=i+1;j<n;j++){
			if(A[j]<A[minX])
				minX=j;
		}
		if(minX!=i){
		t=A[i];
		A[i]=A[minX];
		A[minX]=t;
		sw++;
		}
	
	}
	return sw;

}

void printArray(int A[],int n){
	for(int i=0;i<n-1;i++)
		cout<<A[i]<<" ";
	cout<<A[n-1]<<endl;
}

int main(){
	int n,A[100],time;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	time=selectionSort(A,n);
	printArray(A,n);
	cout<<time<<endl;
	return 0;
}

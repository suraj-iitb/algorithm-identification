#include<iostream>
using namespace std;
int selectionSort(int A[],int N){
	int i,j,sw=0;
	for(i=0;i<N-1;i++){
		int minj=i;
		for(j=i+1;j<N;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		swap(A[i],A[minj]);
		if(i!=minj)sw++;
	}
	return sw;
}
int main(){
	int i,A[100],N;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>A[i];
	}
	int sw=selectionSort(A,N);
	for(i=0;i<N;i++){
		if(i)cout<<" ";
		cout<<A[i];
	}
	cout<<"\n"<<sw<<endl;
	return 0;
}

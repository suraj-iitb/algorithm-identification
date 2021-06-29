#include<iostream>
using namespace std;
int bubbleSort(int A[],int N){
	int i,j,sw=0;
	for(i=0;i<N-1;i++){
		for(j=N-1;j>i;j--){
			if(A[j-1]>A[j]){
				swap(A[j-1],A[j]);
				sw++; 
			}	
		}
	}
	return sw;
}
int main(){
	int A[100],N,i,sw;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>A[i];
	} 
	sw=bubbleSort(A,N);
	for(i=0;i<N;i++){
		if(i)cout<<" ";
		cout<<A[i];
	}
	cout<<"\n";
	cout<<sw<<endl;
	return 0;
}

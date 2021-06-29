#include<iostream>
using namespace std;

int selectionSort(int A[],int N){
	
	int count=0;
	for(int i=0; i<N-1; i++){
		
		int minj=i;
		for(int j=i; j<N; j++){
			
			if(A[j]<A[minj]){
				
				minj=j;
				
				
			}
			
		}
		swap(A[i],A[minj]);
			if(i!=minj){
			    
			    count++;
			    
			}
		
	}
	
	return count;
	
}

int main(){
	
	int N,count;
	cin >>N;
	int A[N];
	for(int i=0; i<N; i++){
		
		cin >>A[i];
		
	}
	
	count=selectionSort(A,N);
	
	for(int i=0; i<N; i++){
		
		if(i){
			
			cout <<" ";
			
		}
		cout <<A[i];
		
	}
	cout <<endl;
	cout <<count <<endl;
	
}

//#include <stdio.h>
#include <iostream>
using namespace std;

int bubbleSort(int A[], int N){
	int sw=0;
	for(int flag=0;flag<N-1;flag++){
		
		for(int i=N-1;i>flag;i--){	
			if(A[i-1] > A[i]){
				int temp = A[i-1];
	     		A[i-1] = A[i];
		  	    A[i]=temp;
		  	    sw++;
			}   
	    }
    }
    return sw;
}




int main(){
	int A[100],N,sw;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	sw = bubbleSort(A,N);
	
	for(int i=0;i<N;i++){
		if(i==N-1){
			cout<<A[i]<<endl;
		}
		else{ 
			cout<<A[i]<<" ";
		}
	
	}

    cout<<sw<<endl; 
    return 0;
}









#include <stdio.h>
//#include <iostream>
//using namespace std; 

int selectSort(int A[], int N){
	int sw=0;
	int minNum,temp;
	int i,j;
	 
	for(i=0;i<N-1;i++){
		minNum = i;
		
		for(j=i+1;j<N;j++){		
			if(A[j]<A[minNum]){
			minNum = j;
			}		
		}
			if(minNum!=i){
			temp = A[minNum];
			 A[minNum] = A[i];
			 A[i] = temp;
			sw++;
		}	
		
	
    }
    return sw;
}




int main(){
	int A[100],N,sw;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	sw = selectSort(A,N);
	
	for(int i=0;i<N;i++){
		if(i==N-1){
			printf("%d\n",A[i]);
		}
		else{ 
			printf("%d ",A[i]);
		}
	
	}
    printf("%d\n",sw);
    return 0;
}









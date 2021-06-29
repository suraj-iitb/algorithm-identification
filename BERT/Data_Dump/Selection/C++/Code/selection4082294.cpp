#include <iostream>
#include <stdio.h>

using namespace std;

int SelectionSort(int A[],int N){
	int rs,minj;
	rs = 0;
	for(int i = 0 ;i<N;i++){
		minj = i;
		for (int j = i+1;j<N;j++)
		{
			if(A[j]<A[minj]) 
			{
				minj = j;
			}
		}
		swap(A[i],A[minj]);
		if(i != minj){
			rs++;	
		}
	}
	return rs;
} 

int main(){
	int A[100],N,rs;
	scanf("%d",&N);
	for (int i = 0;i<N;i++){
		scanf("%d",&A[i]);
	}
	rs = SelectionSort(A,N);
	for(int i = 0;i<N;i++){
		if(i) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n%d\n",rs);
	return 0;
}

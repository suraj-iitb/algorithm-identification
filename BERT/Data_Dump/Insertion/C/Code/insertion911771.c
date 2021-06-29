#include<stdio.h>

int main(int argc, char* argv[]){

	int A[100];
	int key;
	int i,j,k;

	scanf("%d",&k);
		
	for(j =	0;j < k;j++)
	 scanf("%d",&A[j]);

	for(i = 0;i < k ;i++){
		key = A[i];
		j =	i - 1;
			
		while(j >= 0 &&	A[j] > key){
			A[j + 1] = A[j];
			j--;	
		}	
			A[j + 1] = key;
	for(j =	0;j < k - 1;j++)
		printf("%d ",A[j]);	
        printf("%d\n",A[j]);
	}	
	
	return 0;
}	

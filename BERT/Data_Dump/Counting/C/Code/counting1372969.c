#include <stdio.h>

#define M 2000000

void Sort(int[], int);
int B[M];
int num;

int main()
{
	int array[M],i,k=0;
	
	scanf("%d", &num);

	for(i = 1; i <=num; i++){
		scanf("%d", &array[i]);
	}
	k=array[1];
	
  	for(i=2; i<=num; i++){
      	if(k < array[i]) k = array[i];
  	}
 	Sort(array, k+1);

	for(i = 1; i <= num; i++){
		printf("%d", B[i]);
		if(i!=num) printf(" ");
		if(i==num)printf("\n"); 
	}
	return 0;
}

void Sort(int A[], int k)
{
	int i,j;
	int cau[k];
	for(i =k; i >= 0; i--){
		cau[i] = 0;
	}
	for(i = 1; i <= num; i++){
		cau[A[i]]++;
	}
	 for(i=1; i<k; i++) cau[i] += cau[i-1];
	 
  	for(i=num; i>=1; i--){
    	B[cau[A[i]]] = A[i];
    	cau[A[i]]--;
	}
}

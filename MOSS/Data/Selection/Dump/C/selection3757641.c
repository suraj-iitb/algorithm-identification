#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static int cnt;
int selectionSort(int* A, int N)
{
	int minj;
	int i,j,tmp;
	for(i=0;i<N;i++){
		minj=i;
		
		for(j=i+1;j<N;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		if(i!=minj){
			tmp = A[i];
			A[i]=A[minj];
			A[minj]=tmp;
			cnt++;
		}
	}
	return 0;
}
int 
main(){
	int N;
	int A[100];	
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	
	selectionSort(A,N);
	//printf("%d %d \n",k,j);
	for(i=0;i<N;i++){
	    if(i<N-1)printf("%d ",A[i]);
	    else printf("%d",A[i]);
	}
	printf("\n%d\n",cnt);
 return 0;
}

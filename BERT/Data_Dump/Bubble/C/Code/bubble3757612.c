#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static int cnt;
int bubbleSort(int* A, int N)
{
	int flag=1;
	int i,tmp;
	while(flag){
		flag = 0;
		
		for(i=N-1;i>0;i--){
			if(A[i]<A[i-1]){
				tmp = A[i];
				A[i]=A[i-1];
				A[i-1]=tmp;
				flag=1;
				cnt++;
			}
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
	
	bubbleSort(A,N);
	//printf("%d %d \n",k,j);
	for(i=0;i<N;i++){
	    if(i<N-1)printf("%d ",A[i]);
	    else printf("%d",A[i]);
	}
	printf("\n%d\n",cnt);
 return 0;
}

#include <stdio.h>
void insertionSort(int A[],int N){ // N??????????´??????????0-?????????????????????A
   int i,j,v,l;
   for(i=0;i<N-1;i++){
   		printf("%d ",A[i]);
   }
   printf("%d\n",A[N-1]);
   for (i=1;i<=N-1;i++){ 
     	v = A[i];
     	j = i - 1;
   		while (j >= 0 && A[j] > v){
    		A[j+1] = A[j];
	    	j--;
   			A[j+1] = v;
		}
		for(l=0;l<N;l++){
			if(l!=N-1){
			printf("%d ",A[l]);
			}else{
			printf("%d\n",A[l]);
			}
		}
	}

}

int main(){
	int i,n;
	int num[100];
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}

	insertionSort(num,n);
	return 0;
}

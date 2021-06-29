#include <stdio.h>

int main(){
    int i,minj,j,k,N;
    int A[100];
    int count=0;
    
    scanf("%d",&N);

    
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
        }
         for(i=0;i<N-1;i++){
         minj = i;
         for(j=i;j<N;j++){
           if(A[j] < A[minj]){
             minj = j;
	 }
        
	 } if(i!=minj){
	 
	 k=A[i];
	 A[i]=A[minj];
	 A[minj]=k;
	count++;
	 }
	 }
	     for(i=0;i<N;i++){
        if(i>0)printf(" ");
        printf("%d",A[i]);
    }
	     printf("\n");
	     printf("%d\n",count);
    
    return 0;
} 

#include<stdio.h>
int main(){
  int i,j,N,S,c=0,minj;
  int A[100];
  scanf("%d",&N);
 
  for (i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj=j;

      }
    }
      S=A[i];
      A[i]=A[minj];
      A[minj]=S;
        if(A[minj]>A[i]){
	c++;
	}
      
    
  
  }
 
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",c);	 
  return 0;
}

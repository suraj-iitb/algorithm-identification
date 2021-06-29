#include<stdio.h>
int main(){
  int i,j,N,S,c=0;
  int A[100];
  scanf("%d",&N);
 
  for (i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(j=0;j<N;j++){
    for(i=N-1;i>0;i--){
      if(A[i]<A[i-1]){
	S=A[i-1];
	A[i-1]=A[i];
	A[i]=S;
	c++;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",c);	 
  return 0;
}

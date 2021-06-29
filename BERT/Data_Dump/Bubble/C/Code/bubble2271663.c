#include<stdio.h>
#define ko 100
int main(){
  int i,j,N,A[ko],flag=1,im,cou=0;

  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  i=0;
  while(flag){
    flag=0;
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	im=A[j];
	A[j]=A[j-1];
	A[j-1]=im;
	flag=1;
	cou++;
      }
    
    }
    i++;
  }
  for(i=0;i<N;i++){
  printf("%d",A[i]);
  if(i!=N-1)printf(" ");
  }
  printf("\n%d\n",cou);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>

int main(){

  int *A,i,minj,n,j,k,s=0;

  scanf("%d",&n);

  A=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
 
  for(i=0;i<n;i++){
    minj=i;
    for(j=i+1;j<n;j++){
      if(A[j]<A[minj]){
	
	minj=j;
      }}
    if(i !=minj){
    	k=A[i];
	A[i]=A[minj];
	A[minj]=k;s++;}
      }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i !=n-1)printf(" ");
  }printf("\n");
  printf("%d\n",s);
  return 0;
}


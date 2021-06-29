#include<stdio.h>
#define N 2000000
int A[N];
int B[N];
int C[N];
main(){
  int i,j,k=0,len;
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&A[i]);
    if(k<A[i])k=A[i];
  }
  for(i=0;i<=k;i++)
    C[i]=0;
  for(i=0; i<len; i++)
    C[A[i]]++;
  for(i=1; i<=k; i++)
    C[i]=C[i]+C[i-1];
  for(j=len; j>=0; j--){
    B[C[A[j]]-1]=A[j];
    C[A[j]]--;
  }  
  for(i=0;i<len;i++){
    printf("%d",B[i]);
    if(i !=len-1)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
  
}

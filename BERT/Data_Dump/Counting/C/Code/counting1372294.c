#include<stdio.h>
#define N 2000000
int A[N];
int B[N];
int C[N];
main(){
  int i,j,k=0,l;
  scanf("%d",&l);
  for(i=0;i<l;i++){
    scanf("%d",&A[i]);
    if(k<A[i])k=A[i];
  }
  for(i=0;i<=k;i++)
    C[i]=0;
  for(i=0; i<l; i++)
    C[A[i]]++;
  for(i=1; i<=k; i++)
    C[i]=C[i]+C[i-1];
  for(j=l; j>=0; j--){
    B[C[A[j]]-1]=A[j];
    C[A[j]]--;
  } 
  for(i=0;i<l;i++){
    printf("%d",B[i]);
    if(i !=l-1)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
   
}

#include<stdio.h>
int C[2000001],B[2000001];
long n;
Counting_Sort(int A[],int k){
  int i,j; 
 for(i=0;i<=k;i++) C[i]=0;
 for(j=1;j<=n;j++) C[A[j]]=C[A[j]]+1;
 for(i=1;i<=k;i++) C[i]=C[i]+C[i-1];
 for(j=n;j>0;j--){
   B[C[A[j]]]=A[j];
   C[A[j]]=C[A[j]]-1;
 }
} 


int main(){
  int A[2000001];
  int i;
  int max=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(max<A[i]) max=A[i];
  }
  
  Counting_Sort(A,max);
  for(i=1;i<=n;i++){
    if(i==n){
      printf("%d",B[i]);
      break;
    }
    printf("%d ",B[i]);
  } 
  printf("\n");
  
  return 0;  
  
}

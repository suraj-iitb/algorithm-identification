#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,n,max_num=0,*A,*B,*C,*D;
  scanf("%d",&n);

  A = malloc(sizeof(int)*n);
  B = malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(max_num < A[i]){
      max_num = A[i];
    }
  }

  C = malloc(sizeof(int)*max_num+1);
  D = malloc(sizeof(int)*max_num+1);
  for(i=0;i<=max_num;i++)C[i]=0;
  
  for(i=0;i<n;i++)C[A[i]]++;
  for(i=0;i<=max_num;i++){
    if(i==0)D[i]=C[i];
    else D[i]=C[i]+D[i-1];
  }

  for(i=n-1;i>=0;i--){
    B[D[A[i]]-1] = A[i];
    D[A[i]]--;
  }
  for(i=0;i<n;i++){
    if(i == n-1)printf("%d\n",B[i]);
    else printf("%d ",B[i]);
  }
  free(A);
  free(B);
  free(C);
  free(D);  
  return 0;
}

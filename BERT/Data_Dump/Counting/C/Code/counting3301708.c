#include<stdio.h>
#define k 10001
//typedef long int li;

int A[2000005];
int B[2000005];

int main(){
  int n;
  int i,j;
  
  scanf("%d",&n);
  
  for(i=0;i < n;i++) scanf("%d",&A[i]);

  int C[k];

  for(i = 0;i < k;i++) C[i]=0;

  for(j = 0;j < n;j++) C[A[j]]++;

  for(i = 1;i < k;i++) C[i]=C[i]+C[i-1];

  for(j = n-1;j >= 0;j--){
    B[C[A[j]]-1]=A[j];
    C[A[j]]--;
  }
  for(i=0;i<n;i++){
    if(i) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  return 0;
}


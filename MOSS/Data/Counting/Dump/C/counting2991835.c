#include <stdio.h>
#include <stdlib.h>
int main(){
  int *A,*B,i,n,k,max=-1;
  scanf("%d",&n);
  A=malloc(sizeof(int)*(n+2));
  B=malloc(sizeof(int)*(n+2));
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i]>max)max=A[i];
   
  }
  int *C=malloc(sizeof(int)*(max+2));
  
  for(i=0;i<=max;i++)C[i]=0;
  for(i=0;i<n;i++)C[A[i]]++;
  int j=0;
  i=0;
  while(1){
    if(j==max+1)break;
      if(C[j]==0){
      j++;
      continue;
    }
    B[i]=j;
    C[j]--;
     i++;
  }
  for(i=0;i<n;i++){
    printf("%d",B[i]);
    if(i!=n-1)printf(" ");
    else printf("\n");
  }
  return 0;
}


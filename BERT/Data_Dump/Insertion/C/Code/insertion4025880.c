#include<stdio.h>

int main(){
  int i,j,A[1000],v,n,k;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=1;i<n;i++){
    for(k=0;k<n-1;k++){
    printf("%d ",A[k]);

  }
    printf("%d",A[n-1]);
    printf("\n");
    v=A[i];
    
  
  
    j=i-1;
    while((j>=0)&&(A[j]>v)){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;}}
for(k=0;k<n-1;k++){
    printf("%d ",A[k]);

  }
 printf("%d",A[n-1]);
 printf("\n");
    
  
 return 0;
  
}


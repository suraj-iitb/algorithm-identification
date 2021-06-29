#include <stdio.h>
#define N 100
int main(){
  int num=0,n,k;
  int A[N];
  int j,min,i;
  scanf("%d",&n);  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  } 
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[j]<A[min]) min=j;
    }
     if(i!=min) num++; 
    k=A[min];
    A[min]=A[i];
    A[i]=k;
     }
  for(k=0;k<n-1;k++){
    printf("%d ",A[k]);
  }
  printf("%d",A[n-1]);
  printf("\n");
  printf("%d\n",num);
  return 0;
}


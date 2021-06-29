#include<stdio.h>
#define N 100
#define MAX 1000

int main(){
  int i,j,k,n,A[N],key;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);

  for(j=1;j<n;j++){
    key=A[j];
    i=j-1;
    while(i>=0 && A[i]>key){
      A[i+1]=A[i];
      i--;
    }
    A[i+1]=key;

    for(k=0;k<n-1;k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[n-1]);

  }
  
  return 0;
}
    
    


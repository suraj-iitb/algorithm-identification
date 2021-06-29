#include<stdio.h>
int main(){
  int n;
  int a,b,i,j;

  scanf("%d",&n);
  
  int A[n];
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(j=0;j<n;j++){
    if(j>0)printf(" ");
    printf("%d",A[j]);
  }
  printf("\n");
  
  for(i=1;i<n;i++){
    a=A[i];
    b=i-1;
    while(b>=0&&A[b]>a){
      A[b+1]=A[b];
      b--;
    }
    A[b+1]=a;
    for(j=0;j<n;j++){
      if(j>0)printf(" ");
      printf("%d",A[j]);
    }
    printf("\n");
  }

  return 0;
}


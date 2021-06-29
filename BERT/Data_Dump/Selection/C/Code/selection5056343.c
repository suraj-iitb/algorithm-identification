#include <stdio.h>
#define N 100
int main(){
  int i,j,n,flag,temp,count=0,minj;
  int A[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    if(i!=minj){
      temp=A[minj];
      A[minj]=A[i];
      A[i]=temp;
      count++;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}


#include <stdio.h>
#define N 100
int main(){
  int A[N],n,i,j,minj,t,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    t=A[i];
    A[i]=A[minj];
    A[minj]=t;
    if(i !=minj){
      count++;
    }
    }
    for(i=0;i<n;i++){
      if(i>0)printf(" ");
      printf("%d",A[i]);
    }
    printf("\n%d\n",count);
  }


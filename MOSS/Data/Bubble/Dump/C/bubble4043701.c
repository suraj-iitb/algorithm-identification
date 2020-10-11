#include <stdio.h>
#define N 100
int main(){
  int A[N],n,i,j,count=0,sirusi=1,t;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    }
  for(i=0;sirusi;i++){
    sirusi=0;
    for(j=n-1;j>=i+1;j--){
      if (A[j]<A[j-1]){
        t = A[j];
        A[j]=A[j-1];
        A[j-1]=t;
        sirusi=1;
        count++;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}


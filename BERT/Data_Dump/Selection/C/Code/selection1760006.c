#include<stdio.h>
#define N 100
int main(){
  int i,j,n,key,A[N],count=0,mini;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=n-1;i++){
    mini=i;
    for(j=i;j<=n-1;j++){
    if(A[j]<A[mini]){
      mini=j;
    }
    }
    if(A[i]>A[mini]){
      key=A[i];
      A[i]=A[mini];
      A[mini]=key;
      count++;
    }
  }
  printf("%d",A[0]);
  for(i=1;i<n;i++){
    printf(" %d",A[i]);
  }
  printf("\n%d\n",count);
      return 0;

  }

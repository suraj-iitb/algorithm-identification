#include<stdio.h>
#define N 100

int main(){

  int i,j,mini,n,count=0,key;
  int A[N];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<=n-1;i++){
    mini = i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[mini]){
	mini=j;
      }
    }
    if(A[i] != A[mini]){
    key = A[i];
    A[i] = A[mini];
    A[mini] = key;
    count++;
    }
  }
  
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);

  return 0;
  
}


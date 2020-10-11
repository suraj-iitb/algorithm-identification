#include<stdio.h>

void select(int A[],int n){
  int i,j,mini,k,count=0;
  for(i=0;i<=n-1;i++){
    mini = i;
    for(j=i;j<=n-1;j++){      
      if(A[j]<A[mini]){
	mini =j;
      }
    }
    if(i!=mini){
    k = A[i];
    A[i]=A[mini];
    A[mini] = k;
    count++;
    }
  }
  for(i=0;i<n;i++){
    if(i>=1)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
}

int main(){
  int i,j,n,A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  select(A,n);
  return 0;
}

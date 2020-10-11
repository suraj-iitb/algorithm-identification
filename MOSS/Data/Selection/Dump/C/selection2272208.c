#include <stdio.h>
#define N 100
int main(){
  int n,i,j,temp,minj,flag,count=0;
  int A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    minj=i;
    for(j=i+1;j<n;j++){
      if(A[j]<A[minj])	minj=j;
    }
    if(A[i]>A[minj]){
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      count++;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

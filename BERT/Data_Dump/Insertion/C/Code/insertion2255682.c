#include<stdio.h>
int main(){
  int i,j,v,n,k;
  int A[1000];
  scanf("%d",&n);
  for(i=0;i<=n-1;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n-1;i++){
    printf("%d",A[i]);
     printf(" ");
  }
  printf("%d\n",A[n-1]);
  for(i=1;i<=n-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(k=0;k<n-1;k++){
      printf("%d",A[k]);
      printf(" ");
    }
    printf("%d\n",A[n-1]);
  }
  return 0;
}

#include<stdio.h>
void t(int A[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}
int main(){
  int i,j,n,key,A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  t(A,n);
  for(i=1;i<n;i++){
    key=A[i];
    j=i-1;
    while(j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
    }
     A[j+1]=key;
      t(A,n);
  }
  return 0;
}


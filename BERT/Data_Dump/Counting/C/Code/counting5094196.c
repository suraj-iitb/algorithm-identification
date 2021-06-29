#include<stdio.h>
#define N 20000000
void CS(int);
int A[N],B[N],C[10001];
int main(){
  int n,i;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }
  CS(n);
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n)printf(" ");
  }
  printf("\n");

  return 0;
}
void CS(int n){
  int i;
  for(i=0;i<=10001;i++){
    C[i]=0;
  }
  for(i=1;i<=n;i++){
    C[A[i]]++;
  }
  for(i=1;i<=10001;i++){
    C[i]=C[i]+C[i-1];
  }
  for(i=n;i>0;i--){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
}

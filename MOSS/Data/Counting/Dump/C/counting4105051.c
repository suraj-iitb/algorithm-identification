#include<stdio.h>
#define N 10000
int total;
int counting(int A[],int B[],int a){
  int i,j;
  int C[a];
  for(i=0;i<=a;i++){
    C[i]=0;
  }
  for(j=1;j<=total;j++){
    C[A[j]]++;
  }
  for(i=1;i<=a;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=total;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  return 0;
    }
   int main(){
       scanf("%d",&total);
  int i,A[total],B[total];
  for(i=1;i<=total;i++){
    scanf("%d",&A[i]);
  }
  counting(A,B,N);
  for(i=1;i<=total;i++){
    if(i>1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  return 0;
}

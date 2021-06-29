#include<stdio.h>
#define N 2000000
#define T 10000
int A[N+1],B[N+1],n;
void CountingSort(int *A,int *B,int k){
  int i,j,C[N];
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]=C[A[j]]+1;
  }

  for(i=1;i<=k;i++){
    C[i] = C[i]+C[i-1];
  }

  for(j=n;j>0;j--){
      B[C[A[j]]]=A[j];
      C[A[j]]--;
    }
  
}
int main(){
  int k =0,i;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(A[i]>=k) k=A[i];
  }
  k++;
  CountingSort(A,B,k);

  for(i=1;i<=n;i++){
    if(i!=1) printf(" ");
    printf("%d",B[i]);
    // printf("(%d)",i);
    //printf("%d",A[i]);
  }
  printf("\n");
  return 0;

}

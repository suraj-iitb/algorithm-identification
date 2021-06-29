#include <stdio.h>
#define N 2000001

int B[N],C[N];

void CountingSort(int A[],int B[],int m,int n){
  int i,j;
  for(i=0;i<m+1;i++){
    C[i]=0;
  }
  for(j=1;j<n+1;j++){
    C[A[j]]++;
  }
  for(i=1;i<m+1;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<n+1;i++){
    printf("%d",B[i]);
    if(i!=n){
      printf(" ");
    }
  }
  printf("\n");
}
int main(){
  int A[N];
  int i,j,m,n;
  m=0;
  scanf("%d",&n);
  for(i=1;i<n+1;i++){
    scanf("%d",&A[i]);
    if(m<=A[i]-1){
      m=A[i];
    }
  }
    CountingSort(A,B,m,n);
    return 0;
  }


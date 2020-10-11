#include<stdio.h>
int N,k=10000;
void counting(int *,int *,int);
int main(){
  int i;
  scanf("%d",&N);
  int A[N],B[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i+1]);
  }
  counting(A,B,k);
  return 0;
}

void counting(int A[],int B[],int h){
  int i,j,s;
  int C[h];
  for(i=0;i<=h;i++){
    C[i]=0;
  }
  for(j=1;j<=N;j++){
    C[A[j]]++;
  }
  for(i=1;i<=h;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=1;j<=N;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  printf("%d",B[1]);
  for(s=2;s<=N;s++){
    printf(" %d",B[s]);
  }
  printf("\n");

}


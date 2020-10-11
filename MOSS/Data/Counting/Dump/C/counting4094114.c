#include<stdio.h>
#define MAX 2000000

void Counts(int *,int *,int);
int C[MAX];
int n;

int main() {

  int num[MAX],ans[MAX];
  int i;

  scanf("%d",&n);
  for(i=1;i<=n;i++) scanf("%d",&num[i]);
  
  int max = 0;
  for(i=1;i<=n;i++) if(max<=num[i]) max=num[i];

  Counts(num,ans,max);

  for(i=1;i<=n;i++) {
    if(i>1) printf(" ");
    printf("%d",ans[i]);
  }
  printf("\n");

  return 0;

}

void Counts(int A[n],int B[n],int k) {

  int i,j;
  
  for(i=0;i<=k;i++) C[i]=0;

  for(j=1;j<=n;j++) C[A[j]]++;

  for(i=1;i<=k;i++) C[i] = C[i] + C[i-1];

  for(j=n;j>=1;j--) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

#include <stdio.h>

int N=100;
int count=0;
void BubbleSort(int A[],int n){
int a,b,tmp;
for(a=0;a<=n-1;a++){
  for(b=n-1;b>=a+1;b--){
    if(A[b]<A[b-1]){
      tmp=A[b];
      A[b]=A[b-1];
      A[b-1]=tmp;
      count++;
      }
    }
  }
}

int main(){
  int i,j,n;
  int A[N+1];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  BubbleSort(A,n);

  for(j=1;j<=n;j++){
    if(j>1)printf(" ");
  printf("%d",A[j-1]);
  }

  printf("\n");
  printf("%d\n",count);

  return 0;
}


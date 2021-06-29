#include<stdio.h>

static const int N = 100;

int main(){
  int n,i,j,k;
  int min;
  int temp;
  int count=0;
  int A[N];

  /*scanf data*/
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  /*selection sort*/
  for(i=0;i<n-1;i++){
    min=A[i];
    k=i;
    for(j=i+1;j<n;j++){
      if(A[j]<min){
      min=A[j];
      k=j;
      }
    }
    if(A[i]!=A[k]){
      count++;
      temp=A[i];//
      A[i]=A[k];//swap
      A[k]=temp;//
    }
  }

  /*printf data*/
  printf("%d",A[0]);
  for(i=1;i<n;i++)printf(" %d",A[i]);
  printf("\n%d\n",count);
  return 0;
}

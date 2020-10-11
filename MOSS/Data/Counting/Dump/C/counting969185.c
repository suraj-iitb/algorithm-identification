#include <stdio.h>
#define N 2000000

int A[N],B[N];
int count[N];
void CountingSort(int [],int [],int);

main(){
  
  int k,i,j;
  
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&A[i]);
  }
  CountingSort(A,B,k);
  for(i=0;i<k;i++){
    printf("%d",B[i]);
    if(i < k-1)
      printf(" ");
    else
      printf("\n");
  }
  return 0;

}

void CountingSort(int a[],int b[],int n){
  int i;

  for(i=0 ; i<=N ; i++){
    count[i] = 0;

    for(i=0 ; i<n ;i++)
      count[a[i]]++;

    for(i=0 ; i < N ; i++)
      count[i+1] += count[i];
  }

  for(i=n-1;i>=0;i--){
    b[--count[a[i]]] = a[i];
  }
}

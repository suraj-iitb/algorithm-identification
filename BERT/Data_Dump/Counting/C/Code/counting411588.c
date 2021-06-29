/* A Counting Sort */

#include<stdio.h>

int n; /* 1<=n<=2000000 */

void CountingSort(short int A[], short int B[], int k);

int main(){
  int i, k=0;

  scanf("%d",&n);
  short int A[n+1]; /* 0<=A[i]<=10000 */
  short int B[n+1];

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(k<A[i])k=A[i];

  }

  CountingSort(A,B,k);
  
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);

  return 0;
}


void CountingSort(short int A[], short int B[], int k){
  int C[k+1];
  int i, j;

  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]=C[A[j]]+1;
    /* C[i] now contains the number of elements equal to i. */
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
    /* C[i] now contains the number of elements less than or equal to i. */
  }
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }
}

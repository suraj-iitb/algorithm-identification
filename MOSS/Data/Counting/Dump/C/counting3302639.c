#include <stdio.h>
#define N 2000000

int A[N],B[N],C[10000];
 
void countingsort(int n,int k){
  int i;
  
  for(i=0;i<k;i++)
    C[i] = 0;

  for(i=0;i<n;i++)
    C[A[i]]++;

  for(i=1;i<=k;i++)
    C[i] += C[i-1];

  for(i=n-1;i>=0;i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
    }

  for(i=0;i<n-1;i++)
    printf("%d ",B[i]);
  printf("%d\n",B[i]);
}

int searchbig(int n){
  int i,max=0;
  for(i=0;i<n;i++){
    if(max < A[i])
      max = A[i];
  }
  return max;
}

int main(){
  int i,n;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  countingsort(n,searchbig(n));

  return 0;
}

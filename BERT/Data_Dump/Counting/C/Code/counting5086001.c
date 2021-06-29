#include<stdio.h>
void CountingSort(int *,int *,int);
int C[10001];
int n;
int main()
{
  int i,k;
  k = 0;
  scanf("%d",&n);
  int A[n];
  int B[n];
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  for(i=0;i<n;i++){
    if(k < A[i]) k = A[i];
  }
    

  CountingSort(A,B,k);

  for(i=0;i<n;i++){
    if(i == n-1) printf("%d\n",B[i]);
    else printf("%d ",B[i]);
  }

  return 0;
}

void CountingSort(int *a,int *b,int k)
{
  int i;
  for(i=0;i <= k;i++){
    C[i] = 0;
  }
  for(i=0;i<n;i++){
    C[*(a+i)]++;
  }
  for(i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }

  for(i=n-1;i>=0;i--){
    *(b+C[*(a+i)]-1) = *(a+i);
    C[*(a+i)]--;
  }
}
  
  


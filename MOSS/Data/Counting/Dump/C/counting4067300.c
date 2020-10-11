#include <stdio.h>

int A[5000000],B[5000000];
int n;

void c_sort(int k){
  int C[5000000];
  int i,j;
  
  for(i = 0;i <= k;i++)C[i] = 0;
  for(j = 1;j <= n;j++)C[A[j]]++;
  for(i = 1;i <= k;i++)C[i] += C[i-1];
  for(j = n;j >= 1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main(){
  int i,max = 0;
  
  scanf("%d",&n);
  for(i = 1;i <= n;i++){
    scanf("%d",&A[i]);
    if(A[i] > max)max = A[i];
  }
  
  c_sort(max);

  for(i = 1;i < n;i++)printf("%d ",B[i]);
  printf("%d\n",B[i]);

  return 0;
}


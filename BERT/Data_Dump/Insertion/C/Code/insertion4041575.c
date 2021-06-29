#include<stdio.h>

int main()
{
  int i,j,v,n,A[1000];
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < n; i++){
    v = A[i];
    j = i -1;
    while((j >= 0) && (A[j] > v)){
      A[j+1] = A[j];
      j--;
    }
      A[j+1] = v;
      for(j = 0; j < n; j++){
      printf("%d",A[j]);
      if(j < n-1)
      printf(" ");
      }
      printf("\n");
  }
  return 0;
}

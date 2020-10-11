#include<stdio.h>
int main()
{
  
  int i = 0;
  int j = 0;
  int N,v,k;

  scanf("%d",&N);

  int A[N];

  for(i = 0 ; i < N ; i++)
    scanf("%d",&A[i]);
  
  for(i = 1 ; i <= N ; i++){
    v = A[i];
    j = i-1;
    
    for(k = 0 ; k < N-1 ; k++){
      printf("%d ",A[k]);
    }
    printf("%d",A[N-1]);
    printf("\n");

    
    while( j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
  }
  return 0;
}


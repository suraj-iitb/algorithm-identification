#include <stdio.h>
int main()
{
  int A[100], i, j, N, v=0, t=0;

  scanf("%d",&N);
  for(i=0 ; i<N ; i++)
    scanf("%d",&A[i]);
  while(1){
    printf("%d",A[t]);
    t++;
    if(t == N)break; 
    printf(" ");
    }
    t = 0;
    printf("\n");

  for(i=1 ; i<N ; i++){
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    while(1){
      printf("%d",A[t]);
      t++;
      if(t == N)break; 
      printf(" ");
    }
    t = 0;
    printf("\n");
    }
    return 0;
  }

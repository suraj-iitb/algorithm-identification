#include <stdio.h>
  
int main(void)
{

  int i, j, k, N, tmp;
  int flag = 1;
   k = 0;

  /*in*/
  scanf("%d", &N);

  int A[N];

  for (i=0; i<N; ++i)
    scanf("%d", &A[i]);

  /*sort*/
  while (flag){
    flag =0;
    for(j = N-1; j>0; j--){
      if (A[j] < A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag =1;
        k++;
      }
     }
  }

  /*out*/
   for (i=0; i<N; ++i){
       if(i == N-1){
         printf("%d\n", A[i]);
       }else{
         printf("%d ", A[i]);
       }
   }
  printf("%d\n", k);
}


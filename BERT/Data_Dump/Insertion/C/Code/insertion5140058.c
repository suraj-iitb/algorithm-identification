#include <stdio.h>
int main(void)
{
  int i, j, v, l, N;

  /*in*/
  scanf("%d", &N);
  int A[N];
  for (i=0; i<N; ++i){
    scanf("%d", &A[i]);
  }
  for (l=0; l<N; ++l){
      if(l == N-1){
        printf("%d\n", A[l]);
      }else{
        printf("%d ", A[l]);
      }
  }

  /*sort*/

  for (i=1; i<N; ++i) {
     v =A[i];
     j = i - 1;
     while ( j >= 0 && A[j] > v){
          A[j+1] = A[j];
          j--;
     }
     A[j+1] = v;

     for (l=0; l<N; ++l){
         if(l == N-1){
           printf("%d\n", A[l]);
         }else{
           printf("%d ", A[l]);
         }
     }

  }

}

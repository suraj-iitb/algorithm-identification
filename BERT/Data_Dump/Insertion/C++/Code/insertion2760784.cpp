/*ALDS1_1_A 挿入ソート*/
#include <stdio.h>

/*配列の要素を順番に出力*/
void trace(int A[], int N){
   int i;
   for(i = 0 ; i < N ; i++){
      if(i > 0 ) printf(" ");
      printf("%d", A[i]);
   }
   printf("\n");
}

/*挿入ソート*/
void InsertionSort(int A[], int N){
   int i, j, v;
   for(i = 1 ; i < N ; i++){
      v = A[i];
      j = i - 1;

      while(j >= 0 && A[j] > v){
         A[j + 1] = A[j];
         j--;
      }
      A[j + 1] = v;
      
      trace(A, N);
   }
}

int main(){
   int N, i, j;
   int A[100];

   scanf("%d", &N);
   for(i = 0 ; i < N ; i++) scanf("%d", &A[i]);

   trace(A, N);
   InsertionSort(A, N);

   return 0;
}


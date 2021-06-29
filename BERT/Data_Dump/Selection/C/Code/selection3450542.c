/* 選択ソート

   最小値を選択する

   selectionSort(A, N) //N個の要素を含む0オリジンの配列A
   for i が 0 から N-1まで
      minj = i
      for j が i から N-1まで
         if A[j] < A[minj]
            minj = j
         A[i]とA[minj]を交換

   数列Aを読み込み、選択ソートで昇順に並び替え、出力するプログラム
   実際に値が交換された回数を出力

*/

#include <stdio.h>

int selectionSort(int a[], int n)
{
   int count = 0;
   int minj = 0;
   int temp = 0;

   for (int i = 0; i < n-1; i++) {
      minj = i;

      for (int j = i; j <= n-1; j++) {
         if (a[j] < a[minj]) {
            minj = j;
         }
      }
      if (i != minj) {
         temp = a[i];
         a[i] = a[minj];
         a[minj] = temp;
         count++;
      }     
   }
   return count;
}


int main()
{
   int n;
   scanf("%d", &n);

   int a[n];
   for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

   int count = 0;

   count = selectionSort(a, n);

   for (int i = 0; i < n; i++) {
      printf("%d", a[i]);
      if (i + 1 < n)
         printf(" ");
      else if (i + 1 == n)
         printf("\n");
   }

   printf("%d\n", count);

   return 0;
}

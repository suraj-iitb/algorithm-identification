/*
 * バブルソート
 * 泡が水面に上がってくるように配列の要素を動かすソート方法。
 * 以下のようなアルゴリズムで並び替える。
 *
 * bubbleSort(A,N)　//N個の要素を含む0オリジンの配列A
 *  flag = 1 // 逆の隣接要素が存在する
 *  while flag
 *    flag = 0
 *    for j が N-1 から 1 まで
 *    　if A[j] < A[j-1]
 *         A[j] とA[j-1]を交換
 *      flag = 1
 *
 * input
 * n(ソートする配列の要素)
 * a b c d ... (ソート前の配列)
 *
 * output
 * a b c d ...(ソートした配列)
 * n(要素の交換回数)
 */
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int n;
	scanf("%d", &n);

   //入力
	int array[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);

	bool flag = true;

   int count = 0;
   int tmp = 0;

   //ソート処理
	while (flag) {

      flag = false;
      
      for (int j = n-1; j >= 1; j--) {
         if (array[j] < array[j-1]) {
            tmp = array[j-1];
            array[j-1] = array[j];
            array[j] = tmp;
            count++;
            flag = true;
         }
      }
	}


   //出力
   for (int i = 0; i < n; i++) {
      printf("%d", array[i]);
      if (i + 1 < n)
         printf(" ");
      if (i == n-1)
         printf("\n");
   }

   printf("%d\n", count);
	return 0;
}


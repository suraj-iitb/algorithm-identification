/*
   一行目にnが与えられる。二行目にn個の要素を持つ数列Sが与えられる。
   三行目にqが与えられる。四行目にq個の要素を持つ数列Tが与えられる。

   Tに含まれる整数の中で、Sに含まれるものの個数Cを出力する。

   input:
   5
   1 2 3 4 5
   3
   3 4 1

   output:
   3
*/

#include <stdio.h>

int linerserch(int S[], int n, int key)
{
   for (int i = 0; i < n; i++)
      if (S[i] == key)
         return 1;

   return 0;
}

int main()
{
   int n;
   scanf("%d", &n);

   int S[n];
   for (int i = 0; i < n; i++)
      scanf("%d", &S[i]);

   int q;
   scanf("%d", &q);

   int T[q];
   for (int i = 0; i < n; i++)
      scanf("%d", &T[i]);

   int count = 0;

   for (int i = 0; i < q; i++)
      if (linerserch(S, n, T[i])) count++;

   printf("%d\n", count);
   return 0;
}

/*　与えられた数列をマージソートを用いて昇順にソートするプログラム　*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int cnt = 0;      /* 関数mergeにおける比較回数のカウント用 */

void merge(unsigned int A[], int, int, int);
void mergeSort(unsigned int A[], int, int);

int main()
{
  int n, i;
  unsigned int *A;

  scanf("%d", &n);
  /* 数列Aを動的に確保し、読み込む */
  A = (unsigned int *)malloc( sizeof(unsigned int) * n);
  for( i = 0; i<n; i++ )
    scanf("%u", &A[i]);

  /* マージソートで昇順にソート　*/
  mergeSort(A, 0, n);

  /*　結果を出力　 */
  for( i = 0; i<n; i++ )
    {
      printf("%u", A[i]);
      if( i != n-1 )
	printf(" ");
    }
  printf("\n%d\n", cnt);

  return 0;
}

/* マージを行う関数　*/
void merge(unsigned int A[], int left, int mid, int right)
{
  int i, j, k, n1, n2;
  unsigned int *L, *R;

  n1 = mid - left;
  n2 = right - mid;

  /* マージ用の一時記憶配列を動的に確保　要素が１つ多いのは末端に番兵を挿入するため　*/
  L = (unsigned int *)malloc( sizeof(unsigned int) * ( n1 + 1) );
  R = (unsigned int *)malloc( sizeof(unsigned int) * ( n2 + 1) );

  for( i = 0; i<n1; i++ )
    L[i] = A[ left + i ];
  for( j = 0; j<n2; j++ )
    R[j] = A[ mid + j ];

  /*　番兵を挿入　*/
  L[i] = UINT_MAX;
  R[j] = UINT_MAX;

  i = 0;
  j = 0;
  /* マージ　*/
  for( k = left; k<right; k++ )
    {
      if( L[i]<= R[j] )
	A[k] = L[i++];
      else
	A[k] = R[j++];
      cnt++;
    }
}

/* マージソートを行う関数　*/
void mergeSort(unsigned int A[], int left, int right)
{
  int mid = (right + left)/2;

  if( left+1 < right )
    {
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);
    }
  else
    return;
}


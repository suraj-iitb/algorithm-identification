#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* カードの情報（数、文字）を記憶する構造体 */
typedef struct{

  int n;
  char c;
  
}Card;

void swap(Card *, Card *);
int partition(Card A[], int, int);
void quicksort(Card A[], int,int);
int isStable(Card A[], Card B[], int);
void mergeSort(Card A[], int, int);
void merge(Card A[], int, int, int);


int main()
{
  Card *A, *B;
  int n, i;

  scanf("%d", &n);
  A = (Card *)malloc( sizeof(Card) * n );      /* カードの配列を動的に確保 */
  B = (Card *)malloc( sizeof(Card) * n );

  /* カード情報を読込み */
  for( i = 0; i<n; i++ )
    scanf(" %c%d", &A[i].c, &A[i].n);

  /* Aの内容をBにコピー */
  for( i = 0; i<n; i++ )
    B[i] = A[i];

  /* Aに対してクイックソートを行う */
  quicksort(A, 0, n-1);
  /* Bに対してマージソートを行う */
  mergeSort(B, 0, n);
  /* 結果を出力 */
  if( isStable(B, A, n) == 1 )
    printf("Stable\n");
  else
    printf("Not stable\n");
  for( i = 0; i<n; i++ )
    printf("%c %d\n", A[i].c, A[i].n);
  
  return 0;
}

/* Card型の a, b を交換する関数 */
void swap(Card *a, Card *b)
{
  Card tmp;

  tmp = *a;
  *a  = *b;
  *b = tmp;
}

/* A[p..r]の配列を各要素がA[q]以下のA[p...q-1]と 各要素がA[q]より大きいA[q+1..r]に分割する関数
   戻り値： インデックスq */
int partition(Card A[], int p, int r)
{
  int i, j;
  Card x;

  x = A[r];
  i = p-1;

  for( j = p; j<r; j++ )
    {
      if( A[j].n <= x.n )
	{
	  i++;
	  swap(&A[j], &A[i]);
	}
    }
  swap(&A[i+1], &A[r]);

  return i+1;
}

/* Card型の配列に対してクイックソートを行う関数 （昇順）*/
void quicksort(Card A[], int p,int r)
{
  int q;
  
  if( p<r )
    {
      q = partition(A, p, r);
      quicksort(A, p, q-1);
      quicksort(A, q+1, r);
    }
}

/* マージを行う関数　*/
void merge(Card A[], int left, int mid, int right)
{
  int i, j, k, n1, n2;
  Card *L, *R;

  n1 = mid - left;
  n2 = right - mid;

  /* マージ用の一時記憶配列を動的に確保　要素が１つ多いのは末端に番兵を挿入するため　*/
  L = (Card *)malloc( sizeof(Card) * ( n1 + 1) );
  R = (Card *)malloc( sizeof(Card) * ( n2 + 1) );

  for( i = 0; i<n1; i++ )
    L[i] = A[ left + i ];
  for( j = 0; j<n2; j++ )
    R[j] = A[ mid + j ];

  /*　番兵を挿入　*/
  L[i].n = INT_MAX;
  R[j].n = INT_MAX;

  i = 0;
  j = 0;
  /* マージ　*/
  for( k = left; k<right; k++ )
    {
      if( L[i].n<= R[j].n )
        A[k] = L[i++];
      else
        A[k] = R[j++];
    }
}

/* マージソートを行う関数　*/
void mergeSort(Card A[], int left, int right)
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

/* マージソートの結果Aとその他のソートSの結果Bを比較することで、ソートアルゴリズムSが安定かどうか判定する関数
   戻り値： 安定である １   安定でない ０ */
int isStable(Card A[], Card B[], int n)
{
  int i;
  
  for( i = 0; i<n; i++ )
    {
      if( A[i].c != B[i].c )
	return 0;
    }
  return 1;
}


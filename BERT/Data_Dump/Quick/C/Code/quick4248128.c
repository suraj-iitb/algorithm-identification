#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100000
#define WRONG 1
#define RIGHT 0

typedef struct
{
  int value;
  char picture;
} Card;

void swap_v(Card [],int,int);
void swap_p(Card [],int,int);
int Judge(Card [],Card [],int);
void QuickSort(Card [],int,int);
int Partition(Card [],int,int);
void MergeSort(Card [],int,int);
void Merge(Card [],int,int,int);

int main()
{
  Card A[MAX],B[MAX];
  int n,value;
  char picture;
  int i;

  scanf("%d",&n);
  for (i = 0;i < n;i++){
    scanf(" %c %d",&A[i].picture,&A[i].value);
  B[i] = A[i];
  }

QuickSort(A,0,n - 1);
MergeSort(B,0,n);

if (Judge(A,B,n))
printf("Not stable\n");

else
  printf("Stable\n");

for (i = 0;i < n;i++){
  printf("%c %d\n",A[i].picture,A[i].value);
}

  return 0;
}

void swap_v(Card A[], int a, int b)
{
  int temp;

  temp = A[a].value;
  A[a].value = A[b].value;
  A[b].value = temp;
}

void swap_p(Card A[], int a, int b)
{
  char temp;

  temp = A[a].picture;
  A[a].picture = A[b].picture;
  A[b].picture = temp;
}

int Judge(Card A[],Card B[],int n){
  int i;

  for (i = 0;i < n;i++){
    if (A[i].picture != B[i].picture)
    return WRONG;
  }

  return RIGHT;
}

void QuickSort(Card A[], int p, int r)
{
  int q;

  if (p < r)
  {
    q = Partition(A, p, r);
    QuickSort(A, p, q - 1);
    QuickSort(A, q + 1, r);
  }
}

int Partition(Card A[], int p, int r)
{
  int x;
  int i, j;

  i = p - 1;
  x = A[r].value;

  for (j = p; j < r; j++)
  {
    if (A[j].value <= x)
    {
      i++;
      swap_v(A, i, j);
      swap_p(A, i, j);
    }
  }

  swap_v(A, i + 1, r);
  swap_p(A, i + 1, r);

  return i + 1;
}

void MergeSort(Card A[], int left, int right)
{
  int mid;

  if (left + 1 < right)
  {
    mid = (left + right) / 2;

    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}

void Merge(Card A[], int left, int mid, int right)
{
  Card *L, *R;
  int n1, n2;
  int i, j, k;

  n1 = mid - left;
  n2 = right - mid;

  L = (Card *)malloc(sizeof(Card) * (n1 + 1));
  R = (Card *)malloc(sizeof(Card) * (n2 + 1));

  for (i = 0; i < n1; i++)
    L[i] = A[left + i];

  for (i = 0; i < n2; i++)
    R[i] = A[mid + i];

  L[n1].value = INT_MAX;
  R[n2].value = INT_MAX;
  i = 0;
  j = 0;

  for (k = left; k < right; k++)
  {
    if (L[i].value <= R[j].value)
    {
      A[k] = L[i];
      i++;
    }

    else
    {
      A[k] = R[j];
      j++;
    }

  }

}

#include <stdio.h>
#include <utility>
#define MAX 100000
using namespace std;
#define SENTINEL 2000000000

struct Card
{
  char suit;
  int value;
};

int partition(Card A[], int p, int r)
{
  Card x = A[r];
  int i = p - 1;
  for (int j = p; j <= r - 1; j++)
  {
    if (A[j].value <= x.value)
    {
      i = i + 1;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}

void quicksort(Card A[], int p, int r)
{
  if (p < r)
  {
    int q = partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}

void merge(Card A[], int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  Card L[n1 + 1], R[n2 + 1];
  for (int i = 0; i < n1; i++)
  {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++)
  {
    R[i] = A[mid + i];
  }
  L[n1].value = SENTINEL;
  R[n2].value = SENTINEL;
  int i = 0, j = 0;
  for (int k = left; k < right; k++)
  {
    if (L[i].value <= R[j].value)
    {
      A[k] = L[i];
      i = i + 1;
    }
    else
    {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(Card A[], int left, int right)
{
  if (left + 1 < right)
  {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main()
{
  int n;
  Card A[MAX], B[MAX];
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%c%d\n", &A[i].suit, &A[i].value);
    B[i].suit = A[i].suit;
    B[i].value = A[i].value;
  }

  quicksort(A, 0, n - 1);
  mergeSort(B, 0, n);
  bool isStable = true;
  for (int i = 0; i < n; i++)
  {
    if (A[i].suit != B[i].suit)
    {
      isStable = false;
    }
  }
  if (isStable)
  {
    printf("Stable\n");
  }
  else
  {
    printf("Not stable\n");
  }

  for (int i = 0; i < n; i++)
  {
    printf("%c %d\n", A[i].suit, A[i].value);
  }
}

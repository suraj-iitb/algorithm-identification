#include <stdio.h>

#define MAX 100000
#define SENTINEL 2000000000

typedef struct {
  char suit;
  int value;
} Card;

void merge(Card *, int, int, int, int);
void mergesort(Card *, int, int, int);
int partition(Card *, int, int, int);
void quicksort(Card *, int, int, int);

Card Left[MAX/2+2];
Card Right[MAX/2+2];

int main()
{
  int n, i, v;
  Card a[MAX], b[MAX];
  char s[10];
  int stable = 1;

  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%s %d", s, &v);
    a[i].suit = s[0];
    b[i].suit = s[0];
    a[i].value = v;
    b[i].value = v;
  }

  mergesort(a, n, 0, n);
  quicksort(b, n, 0, n-1);

  for(i=0; i<n; i++) {
    if(a[i].suit != b[i].suit)
      stable = 0;
  }
  if(stable == 1)
    printf("Stable\n");
  else
    printf("Not stable\n");
  for(i=0; i<n; i++) {
    printf("%c %d\n", b[i].suit, b[i].value);
  }

  return 0;
}

void merge(Card *A, int n, int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;

  for(i=0; i<n1; i++) {
    Left[i] = A[left+i];
  }
  for(i=0; i<n2; i++) {
    Right[i] = A[mid+i];
  }
  Left[n1].value = SENTINEL;
  Right[n2].value = SENTINEL;
  i = 0;
  j = 0;
  for(k=left; k<right; k++) {
    if(Left[i].value <= Right[j].value)
      A[k] = Left[i++];
    else
      A[k] = Right[j++];
  }
}

void mergesort(Card *a, int n, int left, int right)
{
  int mid;
  if(left+1 < right) {
    mid = (left+right)/2;
    mergesort(a, n, left, mid);
    mergesort(a, n, mid, right);
    merge(a, n, left, mid, right);
  }
}

int partition(Card *a, int n, int p, int r)
{
  int i, j;
  Card tmp, x;
  x = a[r];
  i = p-1;
  for(j=p; j<r; j++) {
    if(a[j].value <= x.value) {
      i++;
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }
  tmp = a[i+1];
  a[i+1] = a[r];
  a[r] = tmp;
  return i+1;
}

void quicksort(Card *a, int n, int p, int r)
{
  int q;
  if(p <r) {
    q = partition(a, n, p, r);
    quicksort(a, n, p, q-1);
    quicksort(a, n, q+1, r);
  }
}

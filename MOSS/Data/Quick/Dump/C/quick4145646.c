#include <stdio.h>
#define N 1000000000

typedef struct {
  char suit;
  int value;
}card;

card l[50002], r[50002];

void merge(card a[], int n, int left, int mid, int right)
{
  int i, j, k, n1, n2;

  n1 = mid - left;
  n2 = right - mid;
  for (i = 0; i < n1; i++)
    l[i] = a[left+i];
  for (i = 0; i < n2; i++)
    r[i] = a[mid+i];
  l[n1].value = r[n2].value = N;
  i = j = 0;
  for (k = left; k < right; k++){
    if (l[i].value <= r[j].value)
      a[k] = l[i++];
    else
      a[k] = r[j++];
  }
}

void mergesort(card a[], int n, int left, int right)
{
  int mid;

  if (left+1 < right){
    mid = (left+right)/2;
    mergesort(a,n,left,mid);
    mergesort(a,n,mid,right);
    merge(a,n,left,mid,right);
  }
}

int partition(card a[], int n, int p, int r)
{
  int i, j;
  card x, y;

  y = a[r];
  i = p - 1;
  for (j = p; j < r; j++)
    if (a[j].value <= y.value){
      i++;
      x = a[i];
      a[i] = a[j];
      a[j] = x;
    }
  x = a[i+1];
  a[i+1] = a[r];
  a[r] = x;
  
  return i+1;
}

void quicksort(card a[], int n, int p, int r)
{
  int q;

  if (p < r){
    q = partition(a,n,p,r);
    quicksort(a,n,p,q-1);
    quicksort(a,n,q+1,r);
  }
}

int main()
{
  int n, i, x, stable = 0;
  card a[100000], b[100000];
  char s[10];

  scanf("%d",&n);
  for (i = 0; i < n; i++){
    scanf("%s%d",s,&x);
    a[i].suit = b[i].suit = s[0];
    a[i].value = b[i].value = x;
  }
  mergesort(a,n,0,n);
  quicksort(b,n,0,n-1);
  for (i = 0; i < n; i++)
    if (a[i].suit != b[i].suit)
      stable++;
  if (stable == 0)
    printf("Stable\n");
  else
    printf("Not stable\n");
  for (i = 0; i < n; i++)
    printf("%c %d\n",b[i].suit,b[i].value);

  return 0;
}


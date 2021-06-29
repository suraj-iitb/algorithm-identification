#include <stdio.h>

typedef struct {
  char letter;
  int number;
} card;

int partition(card a[], int p, int r)
{
  card x = a[r];
  int i = p-1;
  for (int j = p; j <= r-1; j++) {
    if (a[j].number <= x.number) {
      i++;
      card temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  card temp = a[i+1];
  a[i+1] = a[r];
  a[r] = temp;
  return i+1;
}

void quicksort(card a[], int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quicksort(a, p, q-1);
    quicksort(a, q+1, r);
  }
}

void merge(card a[], int left, int mid, int right) {
  int n1, n2, i;
  card l[100000], r[100000];
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0; i < n1; i++)
    l[i] = a[left+i];
  for (i = 0; i < n2; i++)
    r[i] = a[mid+i];
  l[n1].number = 2000000000;
  r[n2].number = 2000000000;
  i = 0;
  int j = 0;
  int k;
  for (k = left; k < right; k++) {
    if (l[i].number <= r[j].number) {
      a[k] = l[i++];
    } else {
      a[k] = r[j++];
    }
  }
}

void mergesort(card a[], int left, int right) {
  if (left+1 < right) {
    int mid = (left + right) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main(void)
{
  int n, i, v, stable = 1;
  char a[10];
  card s[100000], t[100000];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %d", a, &v);
    s[i].letter = t[i].letter = a[0];
    s[i].number = t[i].number = v;
  };
  quicksort(s, 0, n-1);
  mergesort(t, 0, n);
  for (i = 0; i < n; i++) {
    if (s[i].letter != t[i].letter) {
      puts("Not stable");
      stable = 0;
      break;
    } 
  }
  if (stable == 1)
    puts("Stable");
  for (i = 0; i < n; i++)
    printf("%c %d\n", s[i].letter, s[i].number);
  return 0;
}


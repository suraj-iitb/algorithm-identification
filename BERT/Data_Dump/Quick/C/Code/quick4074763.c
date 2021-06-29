#include <stdio.h>

#define MAX 100000
#define NMAX 1000000001

typedef struct {
  int num;
  char mark;
} Trump;

int partition(Trump *, int, int);
void quicksort(Trump *, int, int);
void merge(Trump *, int, int, int);
void mergeSort(Trump *, int, int);

int main() {
  int n, i, k;
  Trump card[MAX], cardb[MAX];

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%*c%c%d", &card[i].mark, &card[i].num);
    cardb[i] = card[i];
  }

  

  mergeSort(cardb, 0, n);
  quicksort(card, 0, n-1);

  for (i = 0; i < n; i++) {
    if (card[i].mark != cardb[i].mark) {
      printf("Not stable\n");
      break;
    }
    else if (i == n-1) {
      printf("Stable\n");
    }
  }
  for (i = 0; i < n; i++) {
    printf("%c %d\n", card[i].mark, card[i].num);
  }


  return 0;
}

int partition(Trump *c, int p, int r) {
  int x, i, j;
  Trump temp;

  x = c[r].num;
  i = p-1;

  for (j = p; j < r; j++) {
    if (c[j].num <= x) {
      i++;
      temp = c[i];
      c[i] = c[j];
      c[j] = temp;
    }
  }
  temp = c[i+1];
  c[i+1] = c[r];
  c[r] = temp;
  
  return i+1;
}


void quicksort(Trump *c, int p, int r) {
  int q;
  if (p < r) {
    q = partition(c, p, r);
    quicksort(c, p, q-1);
    quicksort(c, q+1, r);
  }
}

void merge(Trump *data, int left, int mid, int right) {
  int n1, n2, i, j, k;
  Trump *l, *r;

  n1 = mid - left;
  n2 = right - mid;
  
  l = malloc((n1+1) * sizeof(Trump));
  r = malloc((n2+1) * sizeof(Trump));

  for (i = 0; i < n1; i++) {
    l[i] = data[left+i]; 
  }
  for (i = 0; i < n2; i++) {
    r[i] = data[mid+i];
  }
  l[n1].num = NMAX;
  r[n2].num = NMAX;
  
  i = 0;
  j = 0;

  for (k = left; k < right; k++) {
    if (l[i].num <= r[j].num) {
      data[k] = l[i];
      i++;
    }
    else {
      data[k] = r[j];
      j++;
    }
  }
}

void mergeSort(Trump *data, int left, int right) {
  int mid;
  if (left+1 < right) {
    mid = (left + right) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid, right);
    merge(data, left, mid, right);
  }
}


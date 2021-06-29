#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100001
#define INFTY 1000000000

typedef struct{
  char card;
  int num;
}Record;

 
int partition(Record *, int, int);
void quicksort(Record *, int, int);
void merge(Record *, int, int, int);
void mergeSort(Record *, int, int);
int Stable(Record *, Record *);

int n;

int main () {
  int i;
  char str;
  Record data[N], smp[N];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) {
    scanf(" %c %d",&data[i].card,&data[i].num);
    smp[i] = data[i];
  }

  
  quicksort(data, 0, n - 1);
  mergeSort(smp, 0, n);

  if(Stable(data, smp) == 1) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0 ; i < n ; i++) {
    printf("%c %d\n", data[i].card, data[i].num);
  }

  

  return 0;
}







int partition(Record *A, int p, int r) {
  int i, j, x = 0, tmp = 0;
  char str;
  Record data;

  x = A[r].num;
  i = p - 1;


  for(j = p ; j < r ; j++) {
    if(A[j].num <= x) {
      i++;
 
      data = A[i];
      A[i] = A[j];
      A[j] = data;
    }
  }

  data = A[i+1];
  A[i+1] = A[r];
  A[r] = data;
      

  return i+1;
}


void quicksort(Record *p1, int p, int r) {
  int q = 0;

  if(p < r) {
    q = partition(p1, p, r);
    quicksort(p1, p, q - 1);
    quicksort(p1, q + 1, r);
  }
  
}

void merge(Record *data, int left, int mid, int right) {
  int n1 = 0, n2 = 0, i = 0, j = 0, k =0, cnt = 0;
  Record tmp, *L, *R;

  n1 = mid - left;
  n2 = right - mid;

  L = (Record *)malloc(sizeof(Record) * (n1 + 1));
  R = (Record *)malloc(sizeof(Record) * (n2 + 1));

  for(i = 0 ; i < n1 ; i++) {
    L[i] = data[left + i];
  }

  for(i = 0 ; i < n2 ; i++) {
    R[i] = data[mid + i];
  }

  L[n1].num = INFTY;
  L[n1].card = NULL;
  R[n2].num = INFTY;
  R[n2].card = NULL;

  i = 0;
  j = 0;

  for(k = left ; k < right ; k++) {
    cnt++;
    if(L[i].num <= R[j].num) {
      data[k] =L[i];
      i++;
    }
    else {
      data[k] =R[j];
      j++;
    }
  }

  free(L);
  free(R);
  
}


void mergeSort(Record *smp, int left, int right) {
  int mid = 0;

  if(left+1 < right) {
    mid = (left + right)/2;
    mergeSort(smp, left, mid);
    mergeSort(smp, mid, right);
    merge(smp, left, mid, right);
  }
 
}










int Stable(Record *A, Record *smp) {
  int i, j, a, b;

  for(i = 0 ; i < n ; i++) {
    if(A[i].card != smp[i].card) return 0;
  }

  return 1;
}


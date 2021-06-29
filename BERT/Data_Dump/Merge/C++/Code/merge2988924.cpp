#include<stdio.h>

#define LENGTH_N 500000

void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int mergenum = 0;

int main() {
  int i, nl, ql, arrayN[LENGTH_N], q;

  scanf("%d", &nl);
  for(i=0 ; i < nl ; i++) { scanf("%d", &arrayN[i]); }

  mergeSort(arrayN, 0, nl);
  
  for(i=0 ; i < nl ; i++) {
    printf("%d", arrayN[i]);
    if(i != nl-1) { printf(" "); }
  }
  printf("\n");
  printf("%d\n", mergenum);
  
  return 0;
}

void merge(int *array, int left, int mid, int right) {
  int i, j, k, n1, n2, L[LENGTH_N], R[LENGTH_N];

  n1 = mid - left;
  n2 = right - mid;

  for(i=0 ; i < n1 ; i++) { L[i] = array[left + i]; }
  for(i=0 ; i < n2 ; i++) { R[i] = array[mid + i]; }

  L[n1] = 1000000001; //10^9 + 1
  R[n2] = 1000000001; //10^9 + 1

  i=0;
  j=0;
  
  for(k=left ; k < right ; k++) {
    if(L[i] <= R[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = R[j];
      j++;
    }
    mergenum++;
  }
}

void mergeSort(int *array, int left, int right) {
  int mid = 0;
  
  if(left+1 < right) {
    mid = (left + right) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid, right);
    merge(array, left, mid, right);
  }
}


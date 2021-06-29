#include <stdio.h>
#include <stdlib.h>

#define INF 1000000001

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int c = 0;

int main(){
  int i, n, a[500000];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &a[i]);
  
  mergeSort(a, 0, n);
  for(i=0; i<n-1; i++)
    printf("%d ", a[i]);
  printf("%d\n", a[i]);
  printf("%d\n", c);
  
  return 0;
}


void merge(int *a, int left, int mid, int right){
  int n1, n2, i, j, k;
  int *l, *r;

  n1 = mid - left;
  n2 = right - mid;
  l = malloc((n1+1) * sizeof(int));
  r = malloc((n2+1) * sizeof(int));

  for(i=0; i<n1; i++)
    l[i] = a[left + i];
  for(i=0; i<n2; i++)
    r[i] = a[mid + i];
  
  l[n1] = INF;
  r[n2] = INF;

  i = 0;
  j = 0;
  for(k=left; k<right; k++){
    c++;
    if(l[i] <= r[j])
      a[k] = l[i++];
    else
      a[k] = r[j++];
  }
  free(l);
  free(r);
}

void mergeSort(int *a, int left, int right){
  int mid;

  if(left+1 < right){
    mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}


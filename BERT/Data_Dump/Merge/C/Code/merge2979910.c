#include<stdio.h>

#define Max 500000
#define Sen 1000000000

int count;
int l[Max / 2 + 2], r[Max / 2 + 2];

void merge(int a[], int n, int left, int mid, int right){
  int n1, n2, i, j, k;
  n1 = mid - left;
  n2 = right - mid;

  for(i = 0 ; i < n1 ; i++) l[i] = a[left + i];
  for(i = 0 ; i < n2 ; i++) r[i] = a[mid + i];
  l[n1] = r[n2] = Sen;

  i = 0;
  j = 0;
  for(k = left ; k < right ; k++){
    count++;
    if(l[i] <= r[j]){
      a[k] = l[i++];
    }
    else{
      a[k] = r[j++];
    }
  }
}

void mergeSort(int a[], int n, int left, int right){
  if(left + 1 < right){
    int mid;

    mid = (left + right) / 2;
    mergeSort(a, n, left, mid);
    mergeSort(a, n, mid, right);
    merge(a, n, left, mid, right);
  }
}


int main(){
  int a[Max], n, i;
  count = 0;

  scanf("%d", &n);
  for(i = 0 ; i < n ; i++) scanf("%d", &a[i]);

  mergeSort(a, n, 0 , n);

  for(i = 0 ; i < n ; i++){
    if(i) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");

  printf("%d\n", count);

  return 0;
}

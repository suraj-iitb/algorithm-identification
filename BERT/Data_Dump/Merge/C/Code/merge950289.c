#include <stdio.h>
#include <limits.h>

const int MAX = 5e5;
const int INF = INT_MAX;

void merge(int*, int, int, int);
void mergesort(int*, int, int);

int ans;

int main(){
  int n, i, a[MAX];

  scanf("%d" ,&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d" ,a + i);
  }

  mergesort(a, 0, n);

  for(i = 0 ; i < n ; i++){
    printf("%d%c" ,a[i], i != n-1 ? ' ':'\n');
  }
  printf("%d\n" ,ans);

  return 0;
}

void merge(int a[], int left, int mid, int right){
  int n1 = mid - left, n2 = right - mid;
  int L[n1+1], R[n2+1], i, j, k;

  for(i = 0 ; i < n1 ; i++){
    L[i] = a[left + i];
  }

  for(i = 0 ; i < n2 ; i++){
    R[i] = a[mid + i];
  }

  L[n1] = R[n2] = INF;

  for(i = 0, j = 0, k = left ; k < right ; k++, ans++){
    if(L[i] <= R[j]){
      a[k] = L[i++];
    }else{
      a[k] = R[j++];
    }
  }
}

void mergesort(int a[], int left, int right){
  int mid;

  if(left + 1 < right){
    mid = (left + right) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid, right);
    merge(a, left, mid, right);
  }
}

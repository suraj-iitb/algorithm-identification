#include <stdio.h>
#define INF 1000000000
#define N 500000

void merge(int*,int,int,int);
void mergeSort(int*,int,int);

int cnt=0;

int main() {
  int s[N], n, i;
  scanf("%d", &n);
  for(i=0;i<n;i++) scanf("%d", &s[i]);
  mergeSort(s,0,n);
  for(i=0;i<n-1;i++) printf("%d ", s[i]);
  printf("%d\n%d\n", s[i], cnt);
  return 0;
}

void merge(int *s, int left, int mid, int right) {
  int i, j, k, n1, n2;
  n1 = mid - left;
  n2 = right - mid;
  int l[n1], r[n2];
  for(i=0;i<n1;i++) l[i] = s[left+i];
  for(i=0;i<n2;i++) r[i] = s[mid+i];
  l[n1] = INF;
  r[n2] = INF;
  i = 0;
  j = 0;
  for(k=left;k<right;k++) {
    if(l[i]<=r[j]) {
      s[k] = l[i];
      i++;
      cnt++;
    }
    else {
      s[k] = r[j];
      j++;
      cnt++;
    }
  }
  return;
}

void mergeSort(int *s, int left, int right) {
  if(left+1<right) {
    int mid=(left+right)/2;
    mergeSort(s,left,mid);
    mergeSort(s,mid,right);
    merge(s,left,mid,right);
  }
  return;
}


#include<stdio.h>
#define INFINITY 1000000001
#define N 500000

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int cnt = 0;

int main(){
  int s[N];
  int n;
  int i;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &s[i]);
  }

  mergeSort(s, 0, n);

  for(i=0;i<n;i++){
    if(i == n-1) printf("%d\n", s[i]);
    else printf("%d ", s[i]);
  }

  printf("%d\n", cnt);
  
  return 0;
}

void merge(int *s, int left, int mid, int right){
  int n1, n2;
  int i, j, k;
  
  n1 = mid - left;
  n2 = right - mid;
  int l[n1+1], r[n2+1];

  for(i=0;i<n1;i++){
    l[i] = s[left + i];
  }
  for(i=0;i<n2;i++){
    r[i] = s[mid + i];
  }
  l[n1] = INFINITY;
  r[n2] = INFINITY;

  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    if(l[i] <= r[j]){
      s[k] = l[i];
      i++;
      cnt++;
    }
    else{
      s[k] = r[j];
      j++;
      cnt++;
    }
  }
}

void mergeSort(int *s, int left, int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right) / 2;
    mergeSort(s, left, mid);
    mergeSort(s, mid, right);
    merge(s, left, mid, right);
  }
}


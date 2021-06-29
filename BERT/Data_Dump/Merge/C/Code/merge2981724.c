/*マージソート*/
#include <stdio.h>
#define N 1000000

void merge(int *, int, int, int);
void mergeSort(int *, int, int);
int count=0;

int main(){
  int n, s[N], i, j;
  
  /*値の入力*/
  scanf("%d", &n);
  for (i=0; i<n; i++){
    scanf("%d", &s[i]);
  }
  
  mergeSort(s, 0, n);
  
  for (i=0; i<n-1; i++){
    printf("%d ", s[i]);
  }
  
  printf("%d\n", s[n-1]);
  
  printf("%d\n", count);
  
  return 0;
}

void merge(int *s, int left, int mid, int right){
  int n1, n2, i, j, k;
  int l[N], r[N];
  n1 = mid - left;
  n2 = right - mid;
  
  for(i=0; i<n1; i++){
    l[i] = s[left+i];
  }
  for(i=0; i<n2; i++){
    r[i] = s[mid+i];
  }
  
  l[n1] = 1000000000;
  r[n2] = 1000000000;
  
  i=0;
  j=0;
  
  for(k=left; k<right; k++){
    if (l[i] <= r[j]){
      s[k] = l[i];
      i++;
      count++;
    }
    else{
      s[k] = r[j];
      j++;
      count++;
    }
  }
}

void mergeSort(int *s, int left, int right){
  int mid;
  
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(s, left, mid);
    mergeSort(s, mid, right);
    merge(s, left, mid, right);
  } 
  
}


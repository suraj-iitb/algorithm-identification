#include<stdio.h>
#define SIZE 500000
#define INF 2000000000

int cnt = 0;
int S[SIZE];

void merge(int left, int mid, int right){ // left:0, mid:1, right:2
  int i, j, k;
  int n1, n2;
  int L[SIZE+1], R[SIZE+1];

  n1 = mid   - left; // 1 - 0 = 1
  n2 = right - mid;  // 2 - 1 = 1

  for(i = 0; i < n1; i++){
    L[i] = S[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = S[mid + i];
  }
  L[n1] = INF; // L[n1] = {9, INF}
  R[n2] = INF; // R[n2] = {6, INF}

  i = 0;
  j = 0;
  for(k = left; k < right; k++){
      cnt++;
    if(L[i] <= R[j]){
      S[k] = L[i];
      i = i + 1;
    } else {
      S[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int left, int right){
  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int main(){
  int i, n;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  mergeSort(0, n);

  for(i = 0; i < n-1; i++){
    printf("%d ", S[i]);
  }
  printf("%d\n", S[i]);
  printf("%d\n", cnt);
  
  return 0;
}

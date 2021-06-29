#include <stdio.h>
#define INFTY 1000000010;
int cnt = 0;

void merge(int A[500000], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1], i, j, k;
  //L[0...n1]とR[0...n2]をつくる
  for(i = 0; i < n1; i++) L[i] = A[left+i];
  for(i = 0; i < n2; i++) R[i] = A[mid+i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  //代入する
  i = 0;
  j = 0;
  for (k = left; k < right; k++){
    cnt++;
    if (L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergesort(int a[500000], int left, int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergesort(a, left, mid);
    mergesort(a, mid, right);
    merge(a, left, mid, right);
  }
    }

int main(){
  int i, ans[500000], left = 0, right;
  scanf("%d", &right);
  for(i = 0; i < right; i++) scanf("%d", &ans[i]);

  mergesort(ans, left, right);

  for(i = 0; i < right; i++){
    if (i == right-1) printf("%d\n", ans[right-1]);
    else printf("%d ",ans[i]);
  }
  printf("%d\n", cnt);


  return 0;
}


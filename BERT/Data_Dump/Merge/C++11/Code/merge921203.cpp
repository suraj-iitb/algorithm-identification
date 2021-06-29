#include <cstdio>

int merge(int A[], int left, int mid, int right){
  int compare_count = 0;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1];
  for(int i = 0; i < n1; i++){
    L[i] = A[left + i];
  }
  for(int i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  L[n1] = 0x7fffffff;
  R[n2] = 0x7fffffff;
  int i = 0, j = 0;
  for(int k = left; k < right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    compare_count++;
  }
  return compare_count;
}
int mergesort(int A[], int left, int right){
  int compare_count = 0;
  if(left+1 < right){
    int mid = (left + right) / 2;
    compare_count += mergesort(A, left, mid);
    compare_count += mergesort(A, mid, right);
    compare_count += merge(A, left, mid, right);
  }
  return compare_count;
}

int main(){
  int n;
  scanf("%d", &n);
  if(n == 0){
    printf("\n0\n");
    return 0;
  }
  int S[500000];
  for(int i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  int count = mergesort(S, 0, n);
  printf("%d", S[0]);
  for(int i = 1; i < n; i++){
    printf(" %d", S[i]);
  }
  printf("\n");
  printf("%d\n", count);
}

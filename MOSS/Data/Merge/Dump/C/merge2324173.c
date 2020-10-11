#include <stdio.h>

int A[500000], c;

int merge(int left, int mid, int right){
  int n1, n2, i, j = 0, k, L[mid], R[right - mid];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i <= n1-1; i++) L[i] = A[left + i];
  for(i = 0; i <= n2-1; i++) R[i] = A[mid + i];
  L[n1] = 1000000001;
  R[n2] = 1000000001;
  i = 0;
  for(k = left; k <= right-1; k++){
    if(L[i] <= R[j]){
      c++;
      A[k] = L[i];
      i = i + 1;
    }
    else{
      c++;
      A[k] = R[j];
      j = j + 1;
    }
  }

}

int mergeSort(int left, int right){
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
    scanf("%d", &A[i]);
  }
  
  mergeSort(0, n);
  
  for(i = 0; i < n; i++){
    printf("%d", A[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n%d\n", c);

  return 0;
}

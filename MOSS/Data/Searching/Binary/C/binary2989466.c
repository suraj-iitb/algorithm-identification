#include<stdio.h>

int binary_search(int* A, int n, int i){
  int left  = 0, right = n;
  while(left < right){
    int mid = (left+right)/2;
    if(A[mid] == i) return 1;
    if(A[mid] < i) left = mid+1;
    else right = mid;
  }
  return 0;
}

int main(){
  int S[100000], T[50000], n, m, i, num = 0;
  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%d",&S[i]);
  }
  scanf("%d",&m);
  for(i = 0; i < m; i++){
    scanf("%d",&T[i]);
  }
  for(i = 0; i < m; i++) {
    num += binary_search(S, n, T[i]);
  }
  printf("%d\n", num);
  return 0;
}


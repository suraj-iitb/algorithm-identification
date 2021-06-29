#include <bits/stdc++.h>
  
using namespace std;
  
int mergeSort(int left, int right)
{
  if(left + 1 < right) {
    int mid = (left + right) >> 1;
    return (mergeSort(left, mid) + mergeSort(mid, right) + right - left);
  } else {
    return (0);
  }
}
  
int main()
{
  int N, A[500000];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);
  sort(A, A + N);
  for(int i = 0; i < N; i++) {
    if(i > 0) putchar(' ');
    printf("%d", A[i]);
  }
  putchar('\n');
  printf("%d\n", mergeSort(0, N));
}

#include <iostream>
#include <cmath>
#define INFTY 999999999

int n, sum;

void merge(long long int *A, int left, int mid, int right) 
{
  int n1, n2;
  n1 = mid - left;
  n2 = right - mid;
  
  long long int L[n1+1], R[n2+1];
  for(int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for(int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  
  int s, t;
  s = 0; t = 0;
  for(int i = left; i < right; i++) {
    if(L[s] <= R[t]) {
      A[i] = L[s];
      s++;
    }
    else {
      A[i] = R[t];
      t++;
    }
    sum++;
  }
  
}

void mergeSort(long long int A[], int left, int right) 
{
  if(left + 1 < right) {
    int mid = (int)((left + right) / 2);
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main()
{
  std::cin >> n;

  long long int A[n];
  for(int i = 0; i < n; i++) {
    std::cin >> A[i];
  }
  sum = 0;
  mergeSort(A, 0, n);

  for(int i = 0; i < n; i++) {
    if(i != n - 1) {
      std::cout << A[i] << " ";
    }
    else {
      std::cout << A[i];
    }
  }
  std::cout << "\n" << sum << "\n";
}

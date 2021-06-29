#include<iostream>
int main(){
  int n;
  std::cin >> n;
  int A[n];
  for(int i=0; i<n; i++) std::cin >> A[i];
  for(int i=0,j,key; i<n; i++){
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key) A[j+1] = A[j], A[--j+1] = key;
    for(int k=0; k<n; k++) std::cout << A[k] << (k != n-1 ? ' ' : '\n');
  }
  return 0;
}

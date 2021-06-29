#include <iostream>

int N; //整数の長さN
int A[100]; //N個の数列A
int v;
int i,j,k;

int main() {
  std::cin >> N;
  for(i=0;i<N;i++) {
    std::cin >> A[i];
  }
  for(i=0;i<N;i++) {
    if(i==N-1) {
      std::cout << A[i];
    }
    else std::cout << A[i] << ' ';
  }
  std::cout << std::endl;
  for(i=1;i<N;i++) {
    v = A[i];
    j= i-1;
    while(j>=0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k=0;k<N;k++) {
      if(k==N-1) {
      std::cout << A[k];
      }
      else std::cout << A[k] << ' ';
    }
    std::cout << std::endl;
  }
  return(0);
}

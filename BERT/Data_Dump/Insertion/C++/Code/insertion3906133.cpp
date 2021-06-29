#include <iostream>
#include <cmath>

int main() 
{
  int n,v,j;
  std::cin >> n;
  int A[n] = {0};
  for(int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  for(int i = 0; i < n; i++) {
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
      A[j + 1] = v;
    }
    for(int i = 0; i < n; i++) {
      std::cout << A[i];
      if(i != n - 1) {
	    std::cout << " ";  
      }
    }
    std::cout << "\n";
  }

  return 0;
}


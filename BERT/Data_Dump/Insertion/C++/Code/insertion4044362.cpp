#include <iostream>

void print(int *A, int n){
  for(int i=0; i<n; ++i){
    if(i) std::cout << " ";
    std::cout << A[i];
  }
  std::cout <<std::endl;
}

int main()
{
  int n, v, j;
  int A[101];
  std::cin >> n;
  for(int i=0; i<n; ++i) std::cin >> A[i];

  print(A, n);
  for(int i=1; i<n; ++i){
    v = A[i];
    j = i-1;

    while( j>=0 && A[j] > v ){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    print(A, n);
  }

  return 0;
}

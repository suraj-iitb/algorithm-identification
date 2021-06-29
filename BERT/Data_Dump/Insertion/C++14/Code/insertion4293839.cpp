#include<iostream>
#include<algorithm>
#include<vector>

void print_array( std::vector<int> A ){
  for( int i = 0; i < A.size(); i++ )
  {
      std::cout << A[i];
      if( i != A.size()-1 ) std::cout << " ";
  }
  std::cout << std::endl;
}

int main()
{
  int N;
  std::cin >> N;

  std::vector<int> A( N );
  for( int i = 0; i < N; i++ ){
    std::cin >> A[i];
  }

  //挿入ソート
  print_array( A );
  for( int i = 1; i < N; i++ ){
    int v = A[i];
    int j = i - 1;
    while( j >= 0 && v < A[j] ){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    print_array( A );
  }
}


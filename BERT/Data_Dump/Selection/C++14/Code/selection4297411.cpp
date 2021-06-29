#include<iostream>
#include<algorithm>
#include<vector>

void display( std::vector<int> A ){
    for( int i = 0; i < A.size(); i++ ){
      std::cout << A[i];
      if( i < A.size()-1 ) std::cout << " ";
      else std::cout << std::endl;
  }
}

int bubblesort( std::vector<int>& A, int N ){
  int cnt = 0;
  for( int i = 1; i < N; i++ ){
    for( int j = i; j > 0; j-- ){
      if( A[j-1] > A[j] ){
        std::swap( A[j], A[j-1] );
        cnt++;
      } else  break;
    }
  }
  return cnt;
}

int selectionSort( std::vector<int>& A, int N ){
  int cnt = 0;
  for( int i = 0; i < N-1; i++ ){
    int minj = i;
    for( int j = i+1; j < N; j++ ){
      if( A[minj] > A[j] ){
        minj = j;
      }
    }
    if( i != minj ){
      std::swap( A[minj], A[i] );
      cnt++;
    }
  }
  return cnt;
}

int main()
{
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for( auto &a : A ) std::cin >> a;

  int cnt = selectionSort( A, N );

  display( A );

  std::cout << cnt << std::endl;

}


#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int a[ n ];
  for( int i = 0; i < n; i++ ) {
    cin >> a[ i ];
  }

  int swap_cnt = 0;
  for( int i = 0; i < n; i++ ) {
    for( int j = n - 1; j > i; j-- ) {
      if( a[ j ] < a[ j - 1 ] ) {
        swap( a[ j ], a[ j - 1 ] );
        swap_cnt += 1;
      }
    }
  }

  for( int i = 0; i < n; i++ ) {
    cout << a[ i ];
    if( i < n - 1 ) {
      cout << " ";
    }
    else {
      cout << endl;
    }
  }

  cout << swap_cnt << endl;

  return 0;
}


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


  int minidx = 0;
  int swap_cnt = 0;
  for( int i = 0; i < n; i++ ) {
    minidx = i;
    for( int j = i; j < n; j++ ) {
      if( a[ j ] < a[ minidx ] ) {
        minidx = j;
      }
    }
    if( i != minidx ) {
      swap( a[ i ], a[ minidx ] );
      swap_cnt += 1;
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


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


  int mini = 0;
  int swap_cnt = 0;
  for( int i = 0; i < n; i++ ) {
    mini = i;
    for( int j = i; j < n; j++ ) {
      if( a[ j ] < a[ mini ] ) {
        mini = j;
      }
    }
    swap( a[ i ], a[ mini ] );
    if( i != mini ) {
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


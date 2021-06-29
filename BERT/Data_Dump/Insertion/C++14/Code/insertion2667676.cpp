#include <iostream>
#include <array>
using namespace std;

void isort( int a[], int size ) {
  for( int i = 1; i <= size; i++ ) {
    for( int k = 0; k < size; k++ ) {
      cout << a[k] ;
      if( k < size - 1 ) {
        cout << " ";
      }
      else {
        cout << endl;
      }
    }

    int j, key = a[i];
    for( j = i - 1; j >= 0 and a[j] > key; j-- ) {
      a[j+1] = a[j];
    }
    a[j+1] = key;
  }
}

int main()
{
  int n, a[100] = { 0 };

  cin >> n;
  for( int i = 0; i < n; i++ ) {
    cin >> a[i];
  }
  isort( a, n );

  return 0;
}



#include <iostream>
#include <algorithm>

using namespace std;

class BubbleSort
{
 public:
  void solve( int n, int a[] );
};

void BubbleSort::solve( int n, int a[] )
{
  int cnt = 0;
  
  for( int i = 0; i < n; i++ )
    {
      for( int j = n - 1; j > i;j-- )
        {
          if( a[j] < a[j-1] )
            {
              swap( a[j], a[j-1] );
              cnt++;
            }
        }
    }
  
  cout << a[0];
  for( int i = 1; i < n; i++ )
    {
      cout << " " << a[i] ;
    }
  cout << endl;
  cout << cnt << endl;
}

int main( void )
{
  int n;
  int a[100];

  BubbleSort *bs = new BubbleSort();

  cin >> n;

  for( int i = 0; i < n; i++ )
    {
      cin >> a[i];
    }

  bs -> solve( n, a );

  delete bs;

  return 0;
}

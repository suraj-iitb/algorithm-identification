#include <iostream>
#include <algorithm>

using namespace std;

class SelectionSort
{
 public:
  void solve( int n, int a[] );
};

void SelectionSort::solve( int n, int a[] )
{
  int cnt = 0;
  int mini;

  for( int i = 0; i < n; i++)
    {
      mini = i;
      for( int j = i; j < n; j++)
        {
          if( a[j] < a[mini] )
            mini = j;
        }
      if( i != mini )
        {
          swap(a[i], a[mini]);
          cnt++;
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

  SelectionSort *ss = new SelectionSort();

  cin >> n;

  for( int i = 0; i < n; i++ )
    {
      cin >> a[i];
    }

  ss -> solve( n, a );

  delete ss;

  return 0;
}

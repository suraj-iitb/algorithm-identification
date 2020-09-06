#include <iostream>

using namespace std;

class Insertionsort
{
 public:
  void solve( int n, int a[] );
};

void Insertionsort::solve( int n, int a[] )
{
  int key;
  
  for( int i = 0; i < n - 1; i++ )
    {
      cout << a[i] << " ";
    }
  cout << a[n-1] << endl;
      
  for( int j = 1; j < n; j++ )
    {
      key = a[j];
      int k = j - 1;
      while((k >= 0) && (a[k] > key))
        {
          a[k+1] = a[k];
          k--;
        }
      a[k+1] = key;
        
      for( int i = 0; i < n - 1; i++ )
        {
          cout << a[i] << " ";
        }
      cout << a[n-1] << endl;
    }
  
}

int main( void )
{
  int n;
  int a[100];

  Insertionsort *InsertionSort = new Insertionsort();

  cin >> n;
  for( int i = 0; i < n; i++ )
    {
      cin >> a[i];
    }
  
  InsertionSort -> solve( n, a );

  delete InsertionSort;

  return 0;
}

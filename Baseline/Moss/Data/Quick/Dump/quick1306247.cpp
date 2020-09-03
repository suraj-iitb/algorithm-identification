#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <sstream>
#include <string>
#include <utility>
#include <map>
#include <memory>
#include <set>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>

using namespace std;


class QuickSort
{
public:
  int n;
  pair<char,int> *a;
  QuickSort( int x );
  int partition( int p, int r );
  int sort( int p, int r );
};

QuickSort::QuickSort( int x ) : n(x)
{
  a = new pair<char,int> [x];
}

int QuickSort::partition( int p, int r )
{
  int x = a[r].second;
  int i = p - 1;

  for ( int j = p; j < r; j++ )
    {
      if ( a[j].second <= x )
        {
          ++i;
          swap( a[i], a[j] );
        }
    }
  swap( a[i+1], a[r]);
  
  return i+1;
}

int QuickSort::sort( int p, int r )
{
  if ( p < r )
    {
      int q = partition( p, r );
      sort( p, q - 1 );
      sort( q + 1, r );
    }

  return 0;
}

class MergeSort
{
public:
  int n;
  pair<char,int> *a;
  MergeSort( int x );
  int merge( int left, int mid, int right );
  int sort( int left, int right );
};

MergeSort::MergeSort( int x ) : n(x)
{
  a = new pair<char,int> [x];
}

int MergeSort::merge(int left, int mid, int right)
{
  const pair<char, int> infty = make_pair('X', 2000000000);
  int n1 = mid - left;
  int n2 = right - mid;

  pair<char,int> *l = new pair<char,int> [n1 + 1];
  pair<char,int> *r = new pair<char,int> [n2 + 1];

  for ( int i = 0; i < n1; i++ )
    l[i] = a[left + i];
  
  for ( int i = 0; i < n2; i++ )
    r[i] = a[mid + i];

  l[n1] = infty;
  r[n2] = infty;

  int i = 0;
  int j = 0;

  for ( int k = left; k < right; k++ )
    {
      if ( l[i].second <= r[j].second )
        a[k] = l[i++];
      else
        a[k] = r[j++];
    }

  delete[] l;
  delete[] r;
  
  return 0;
}

int MergeSort::sort( int left, int right )
{
  int mid;

  if ( left + 1 < right )
    {
      mid = (left + right) / 2;
      sort( left, mid );
      sort( mid, right );
      merge( left, mid, right );
    }
  
  return 0;
}

int main()
{

  bool stable;
  int n;
  cin >> n;

  char m;
  int v;
  pair<char,int> c;
  
  QuickSort qs(n);
  MergeSort ms(n);
  
  for ( int i = 0; i < n; i++ )
    {
      cin >> m >> v;
      c = make_pair(m, v);
      qs.a[i] = c;
      ms.a[i] = c;
    }
  
  qs.sort( 0, n-1 );
  ms.sort( 0, n );
  
  stable = true;
  
  for ( int i = 0; i < n; i++ )
    {
      if ( qs.a[i] != ms.a[i] )
        {
          stable = false;
          break;
        }
    }

  if ( stable )
    cout << "Stable" << endl;
  else
    cout << "Not stable" << endl;
  
  for ( int i = 0; i < n; i++ )
    cout << qs.a[i].first << " " << qs.a[i].second << endl;
  
  return 0;
}

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

class MergeSort
{
public:
  MergeSort() : cnt(0) {}
  int solve();
  int merge(int left, int mid, int right);
  int mergeSort(int left, int right);
  int showCnt();
  int n, cnt;
  int s[500000];
};

int MergeSort::merge(int left, int mid, int right)
{
  const int infty = 2000000000;
  int n1 = mid - left;
  int n2 = right - mid;

  int *l = new int [n1 + 1];
  int *r = new int [n2 + 1];

  for ( int i = 0; i < n1; i++ )
    l[i] = s[left + i];
  
  for ( int i = 0; i < n2; i++ )
    r[i] = s[mid + i];

  l[n1] = infty;
  r[n2] = infty;

  int i = 0;
  int j = 0;

  for ( int k = left; k < right; k++ )
    {
      cnt++;
      if ( l[i] <= r[j] )
        s[k] = l[i++];
      else
        s[k] = r[j++];
    }

  delete[] l;
  delete[] r;
  
  return 0;
}

int MergeSort::mergeSort(int left, int right)
{
  int mid;

  if ( left + 1 < right )
    {
      mid = (left + right) / 2;
      mergeSort( left, mid );
      mergeSort( mid, right );
      merge( left, mid, right );
    }
  
  return 0;
}

int MergeSort::showCnt()
{
  cout << cnt << endl;
  return 0;
}

int MergeSort::solve()
{
  cin >> n;
  for ( int i = 0; i < n; i++ )
    {
      cin >> s[i];
    }

  mergeSort( 0, n );
  
  for ( int i = 0; i < n; i++ )
    {
      if ( i ) cout << " ";
      cout << s[i];
    }
  cout << endl;

  showCnt();
  
  return 0;
}

int main()
{
  MergeSort ms;

  ms.solve();

  return 0;
}

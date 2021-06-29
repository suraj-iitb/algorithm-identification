#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVector ( vector<int> &v )
{
  for (int i = 0, ilen = v.size(); i < ilen; ++i)
  {
    cout << v[i] << (((i+1) == ilen) ? '\n' : ' ');
  }
}

int main ( void )
{
  int n;
  vector<int> v;

  cin >> n;

  v = vector<int>(n);

  for (int i = 0; i < n; ++i)
  {
    cin >> v[i];
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = i-1; (j >= 0) && (v[j] > v[j+1]); --j)
    {
      swap(v[j], v[j+1]);
    }
    printVector(v);
  }

  return 0;
}

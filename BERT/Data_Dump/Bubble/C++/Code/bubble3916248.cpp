#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <map>
#include <cmath>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

//バブルソートs

int bubbleSort(vector<int> &A, int n)
{
  int cnt = 0;
  bool flag = true;
  while(flag)
  {
    flag = false;
    for(int j = n-1; j >= 1; --j)
    {
      if(A[j] < A[j-1])
      {
        swap(A[j],A[j-1]);
        flag = true;
        ++cnt;
      }
    }
  }
  return cnt;
}

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; ++i)
    {
      cin >> a.at(i);
    }

    int res = bubbleSort(a, n);

    for(int i = 0; i < n; ++i)
    {
      cout << a.at(i);
      if(i != n-1)
      {
        cout << " ";
      }
    }
    cout << endl;

    cout << res << endl;
    return 0;    
}


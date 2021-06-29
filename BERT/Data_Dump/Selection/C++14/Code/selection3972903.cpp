#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <sstream>   
#include<limits.h>
using namespace std;
#define i64  long long
#define lint long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807

bool prime_check(int A)
{
  if( A < 2) return 0;
  for (int i = 2; i <= sqrt(A); i++)
  {
    if(A%i == 0)return 0;
  }
  return 1;
}
void solve()
{
  int N;
  cin>>N;
  vector<int> vec(N,0);
  for (int i = 0; i < N; i++)
  {
    cin>>vec[i];
  }
  int count = 0;
  int min_v;
  
  for (int i = 0; i < N; i++)
  {
    min_v = i;
    for (int j = i ; j <N ; j++)
    {
      if(vec[min_v] > vec[j]) min_v = j;
    }
    if(min_v != i) 
    {swap(vec[i],vec[min_v]);
    count++;
    }
  }

  for (int i = 0; i < N; i++)
  {
    cout<<vec[i];
    if(i != N -1) cout<<" ";
  }

  cout<<endl<<count<<endl;
  
  
  return;
}

int main(int argc, const char *argv[])
{

  solve();

  return 0;
}


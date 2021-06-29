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

void solve()
{

  int N;
  cin>>N;
  vector<int> vec(N,0);
  for (int i = 0; i < N; i++)
  {
    cin>>vec[i];
  }

      for (int i_1 = 0; i_1 < N; i_1++)
    {
      cout<<vec[i_1];
      if(i_1 != N - 1) cout<<" ";
    }

    cout<<endl;

  for (int i = 1; i < vec.size(); i++)
  {
    int key = vec[i];
    int j = i - 1;
    while((j >= 0)&&(vec[j] > key) )
    {
      vec[j+1] = vec[j];
      j--;
    }
    vec[j + 1] = key;

    for (int i_1 = 0; i_1 < N; i_1++)
    {
      cout<<vec[i_1];
      if(i_1 != N - 1) cout<<" ";
    }

    cout<<endl;
    
    
  }
  
  
  
  return;
}

int main(int argc, const char *argv[])
{

  solve();

  return 0;
}


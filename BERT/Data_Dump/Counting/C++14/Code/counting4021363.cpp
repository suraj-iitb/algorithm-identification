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
#include<list>
using namespace std;
#define i64  long long
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807
#define MOD 1000000007


void solve()
{
  int N;
  cin>>N;
  vector<int> vec(N+1,0);
  for (int i = 0; i < N; i++)
  {
    cin>>vec[i];
  }

    N = N + 1;


  vector<int> cnt_vec(100001,0);
  vector<int> out_vec(N,0);
  for (int i = 0; i < N; i++)
  {
    cnt_vec[vec[i]]++;
  }
  for (int i = 0; i <=100000; i++)
  {
    cnt_vec[i+1] += cnt_vec[i];
  }

  for (int i = N-2   ; i >= 0; i--)
  {
    int target = vec[i];
    int suf = cnt_vec[target];
    out_vec[suf-1] = target;
    cnt_vec[target]--;
  }

  for (int i = 1; i < N; i++)
  {
    if(i - 1)cout<<" ";
    cout<<out_vec[i];
  }

  cout<<endl;
  
  
  
  
  

  return;  
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(8);

  solve();

 
  return 0;
}

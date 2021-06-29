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

int L[300000],R[300000];
int counter = 0;
void merge_F(vector<int> &vec,int n,int left,int mid,int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++)
  {
    L[i] = vec[left + i];
  }
  for (int i = 0; i < n2; i++)
  {
    R[i] = vec[mid + i];
  }
  L[n1] = I64_MAX;
  R[n2] = I64_MAX;
  int i = 0, j = 0;
  for (int k = left; k < right; k++)
  {
    counter++;
    if(L[i] <= R[j])
    {
      vec[k] = L[i++];
    }
    else
    {
      vec[k] = R[j++];
    }
    
  }
  
  

  return;
}
void mergeSort(vector<int> &vec,int n,int left,int right)
{
  if(left + 1 < right)//ここらへんの挙動わからん
  {
    int mid = (left + right)>>1;
    mergeSort(vec,n,left,mid);
    mergeSort(vec,n,mid,right);
    merge_F(vec,n,left,mid,right);
  }
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
  mergeSort(vec,N,0,N);

  for (int i = 0; i < N; i++)
  {
    if(i)
    {
      cout<<" ";
    }
    cout<<vec[i];
  }
  cout<<endl;
  cout<<counter<<endl;
  
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

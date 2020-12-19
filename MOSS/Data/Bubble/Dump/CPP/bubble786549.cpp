#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)

//4方向ベクトル→↑←↓
int dx[] ={1,0,-1,0};
int dy[] ={0,-1,0,1};

int A[100];

int main()
{
  int N;
  int ans = 0;
  cin >>N;
  for(int i = 0;i < N;i++){
    cin >>A[i];
  }
  for(int i = 0;i < N;i++){
    for(int j = N-1;j >i;j--){
      if(A[j] <A[j-1]){
	swap(A[j],A[j-1]);
	ans++;
      }
    }
  }
  for(int i = 0;i < N;i++){
    cout <<A[i];
    if(i !=N-1)
      cout <<" ";
  }
  cout <<endl;
  cout <<ans<<endl;
  return 0;
}

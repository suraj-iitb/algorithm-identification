#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
using namespace std;
typedef long long int lli;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define INF 1000000000
#define IOS ios_base::sync_with_stdio(0); cin.tie(0) //making cin faster
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR_R(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REP(i,n)   FOR(i,0,n)
#define REP_R(i,n)   FOR_R(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define SIZ(x) ((int)(x).size())
//int IsPrime(int Nvrbl){int i;if(Nvrbl<2){return 0;}else if(Nvrbl==2){return 1;}else if(Nvrbl%2==0){return 0;}for(i=3;i<=sqrt(Nvrbl);i+=2){if(Nvrbl%i==0){return 0;}}return 1;} // 1 for prime, 0 for not prime

int sort_bubble(vector<int>&,int);

int main(void)
{
  
  int N;
  cin >> N;
  
  vector<int> A(N);

  int cnt;
  
  REP(i,N)
    {
      cin >> A[i];
      
    }

  cnt = sort_bubble(A,N);

  REP(i,N)
    {
      if( i != N-1 )
	{
	  cout << A[i] << " " ;
	}
      else
	{
	  cout << A[i] << "\n" ;
	}
    }

  cout << cnt << "\n" ;
  
  
}

int sort_bubble(vector<int>& A, int N)
{
  int flag;
  int cnt = 0;
  
  
  REP(j,N-1)
    {
      flag = 1;
      

      REP(i,N-1-j)
	{

	  if( A[i] > A[i+1] )
	    {
	      swap(A[i],A[i+1]);
	      flag = 0;
	      ++ cnt;
	      
	    }
	  
	}

      if(flag)
	{
	  break;
	  
	}

      
    }

  return cnt;
  
  
}


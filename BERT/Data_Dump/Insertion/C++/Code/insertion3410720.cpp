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

void insertionSort( vector<int>& , int);

int main(void)
{
  int N;
  scanf("%d\n",&N);
  
  vector<int> A(N);
  REP(i,N)
    {
      if(i != N-1 )
	{
	  scanf("%d ",&A[i]);
	}
      else
	{
	  scanf("%d\n",&A[i]);
	  
	}
    }

  insertionSort(A,N);
  
  
  
  
}

void insertionSort( vector<int>& A , int N )
{
  int v;
  int j;

  REP(i,N)
    {
      if(i != N-1 )
	{
	  printf("%d ",A[i]);
	}
      else
	{
	  printf("%d\n",A[i]);
	  
	}
    }

  FOR(i,1,N)
    {
      v = A[i];
      j = i-1;

      while( j >= 0 and A[j] > v )
	{

	  A[j+1] = A[j];
	  -- j;
	  
	}

      A[j+1] = v;

      REP(i,N)
	{
	  if(i != N-1 )
	    {
	      printf("%d ",A[i]);
	    }
	  else
	    {
	      printf("%d\n",A[i]);
	  
	    }
	}
      
      
      
    }
}


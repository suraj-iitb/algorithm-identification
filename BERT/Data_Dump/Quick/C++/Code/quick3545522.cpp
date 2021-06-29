#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define y0 qvya13579
#define y1 qvyb24680
#define j0 qvja13579
#define j1 qvjb24680
#define next qvne13579xt
#define prev qvpr13579ev
#define INF 1000000007
#define MOD 1000000007
#define PI acos(-1.0)
#define endl "\n"
#define IOS cin.tie(0);ios::sync_with_stdio(false)
#define M_P make_pair
#define PU_B push_back
#define PU_F push_front
#define PO_B pop_back
#define PO_F pop_front
#define U_B upper_bound
#define L_B lower_bound
#define B_S binary_search
#define PR_Q priority_queue
#define FIR first
#define SEC second
#if __cplusplus < 201103L
#define stoi(argument_string) atoi((argument_string).c_str())
#endif
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP_R(i,n) for(int i=((int)(n)-1);i>=0;--i)
#define FOR(i,m,n) for(int i=((int)(m));i<(int)(n);++i)
#define FOR_R(i,m,n) for(int i=((int)(m)-1);i>=(int)(n);--i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define SIZ(x) ((int)(x).size())
#define COUT(x) cout<<(x)<<endl
#define CIN(x) cin>>(x)
#define CIN2(x,y) cin>>(x)>>(y)
#define CIN3(x,y,z) cin>>(x)>>(y)>>(z)
#define CIN4(x,y,z,w) cin>>(x)>>(y)>>(z)>>(w)
#define SCAND(x) scanf("%d",&(x))
#define SCAND2(x,y) scanf("%d%d",&(x),&(y))
#define SCAND3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define SCAND4(x,y,z,w) scanf("%d%d%d%d",&(x),&(y),&(z),&(w))
#define SCANLLD(x) scanf("%lld",&(x))
#define SCANLLD2(x,y) scanf("%lld%lld",&(x),&(y))
#define SCANLLD3(x,y,z) scanf("%lld%lld%lld",&(x),&(y),&(z))
#define SCANLLD4(x,y,z,w) scanf("%lld%lld%lld%lld",&(x),&(y),&(z),&(w))
#define PRINTD(x) printf("%d\n",(x))
#define PRINTLLD(x) printf("%lld\n",(x))
typedef long long int lli;
using namespace std;

bool compare_by_2nd(pair<int,int> a, pair<int,int> b)
{
  if( a.second != b.second )
    {
      return a.second < b.second;
    }
  else
    {
      return a.first < b.first;
    }
  
}

int ctoi(char c)
{
  if( c >= '0' and c <= '9' )
    {
      return (int)(c-'0');
    }

  return -1;
}

int alphabet_pos(char c) 
{
  if( c >= 'a' and c <= 'z' )
    {
      return (int)(c-'a');
    }

  return -1;
}


int alphabet_pos_capital(char c)
{
  if( c >= 'A' and c <= 'Z' )
    {
      return (int)(c-'A');
    }

  return -1;
}


vector<string> split(string str, char ch)
{
  int first = 0;
  int last = str.find_first_of(ch);
  
  if(last == string::npos)
    {
      last = SIZ(str);
    }

  vector<string> result;

  while( first < SIZ(str) )
    {
      string Ssubstr(str, first, last - first);
      result.push_back(Ssubstr);
      first = last + 1;
      last = str.find_first_of(ch, first);

      if(last == string::npos)
	{
	  last = SIZ(str);
	}
    }
  
  return result;
}



int gcd( int a , int b ) // assuming a,b >= 1
{
  if( a < b )
    {
      return gcd( b , a );
      
    }

  if( a % b == 0 )
    {
      return b;
      
    }

  return gcd( b , a % b );
  
}

int lcm( int a , int b ) // assuming a,b >= 1
{
  return  a * b / gcd( a , b );
  
}


/*------------------ the end of the template -----------------------*/

int partition( vector<pair<char,int> >& A , int p , int r )
{
  int i = p-1;
  int x = A[r].second;
  
  FOR(j,p,r)
    {
      if( A[j].second <= x )
	{
	  ++ i;
	  swap(A[i],A[j]);
	  
	}
    }

  swap(A[i+1],A[r]);

  return i+1;
  
}


void quicksort( vector<pair<char,int> >& A , int p , int r )
{
  if( p < r )
    {
      int q = partition(A,p,r);
      quicksort(A,p,q-1);
      quicksort(A,q+1,r);
      
    }
}


void merge( vector<pair<char,int> >& A , int left , int mid , int right )
{
  int n0 = mid - left;
  int n1 = right - mid;

  vector<pair<char,int> > L(n0+1);
  vector<pair<char,int> > R(n1+1);

  REP(i,n0)
    {
      L[i] = A[left+i];
    }

  L[n0].second = INF;
  L[n0].first = '0';
  
  REP(i,n1)
    {
      R[i] = A[mid+i];
      
    }

  R[n1].second = INF;
  R[n1].first = '1';

  int i = 0;
  int j = 0;
  int k = left;
  
  while( k < right )
    {
      if( L[i].second <= R[j].second )
	{
	  A[k] = L[i];
	  ++ i;
	  
	}
      else
	{
	  A[k] = R[j];
	  ++ j;
	}
      
      ++ k;
    }
  
  
}


void mergesort( vector<pair<char,int> >& A , int left , int right )
{
    
  if( left + 1 < right )
    {
      int mid = (left+right)/2;
      
      mergesort(A,left,mid);
      mergesort(A,mid,right);
      merge(A,left,mid,right);
      
    }
  
}



int main()
{
  IOS; /* making cin faster */
  int N;
  scanf("%d\n",&N);
  

  vector<pair<char,int> > A(N);
  vector<pair<char,int> > B;

  int k;
  char c;
  
  REP(i,N)
    {
      scanf("%c %d\n",&c,&k);
      A[i].first = c;
      A[i].second = k;
      
    }

  B = A;

  quicksort(A,0,N-1);
  mergesort(B,0,N);

  int flag_stable = 1;

  REP(i,N)
    {
      if( A[i] != B[i] )
	{
	  flag_stable = 0;
	  break;
	  
	}
    }

  if( flag_stable )
    {
      printf("Stable\n");
    }
  else
    {
      printf("Not stable\n");
      
    }

  REP(i,N)
    {
      printf("%c %d\n",A[i].first,A[i].second);
      
    }
  
  
  
  

}


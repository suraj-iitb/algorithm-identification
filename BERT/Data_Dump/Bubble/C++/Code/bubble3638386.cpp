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

using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++) cin>>A[i];
  int ans=0;
  bool flag=1;
  while(flag){
    flag=0;
    for(int j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	swap(A[j],A[j-1]);
	flag=1;
	ans++;
      }
    }
  }
  for(int i=0;i<n;i++) cout<<A[i]<<" \n"[i==n-1];
  cout<<ans<<endl;
  return 0;
}

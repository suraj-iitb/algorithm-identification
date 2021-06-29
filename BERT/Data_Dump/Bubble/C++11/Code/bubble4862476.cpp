#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
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
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vll>;
const double EPS = 1e-9;
const long long MOD=1e9+7;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void bubble_sort(vll &a, ll n){
  bool f=true;
  ll c=0;
  while(f){
    f=false;
    for(int j=n-1; j>=1; j--){
      if(a[j] < a[j-1]){
        swap(a[j],a[j-1]);
        c++;
        f=true;
      }
    }
  }
  rep(i,n-1){
    cout<<a[i]<<" ";
  }
  cout<<a[n-1]<<endl;
  cout<<c<<endl;
}
int main(){
  ll n; cin>>n;
  vll a(n); rep(i,n) cin>>a[i];
  bubble_sort(a,n);
}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<algorithm> // sort
#include<map> // pair
#include<cmath>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll tmp1,tmp2;
const ll mod = 1e9+7;
const int INF = 1e9;
const ll INFLONG = 1e18;
void swap(ll *x,ll *y){
  ll tmp = *x;
  *x = *y;
  *y = tmp;
}
void selectionsort(ll num,vector<ll> vec){
  ll sum = 0;
  rep(i,num){
    ll minj = i;
    REP(j,i,num){
      if(vec[minj] > vec[j]){
        minj = j;
      }
    }
    // cout << i << " " << minj << endl;
    if(minj != i){
      swap(&vec[i],&vec[minj]);
      sum++;
    }
  }
  rep(i,num){
    if(i == num-1){cout << vec[i];break;}
    cout << vec[i] << " ";
  }
  cout << endl;
  cout << sum << endl;
}
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  selectionsort(n,a);
}


//
// Created by 吉川純平 on 2019-12-01.
//

#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
//using ull = unsigned long long;
#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll tmp1,tmp2,tmp3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;
void swap(ll *x,ll *y){
  ll tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}
ll maxi = 10001;
void countingSort(vector<ll> &vec,ll n){
  vector<ll> count_vec(maxi,0);
  rep(i,n){
    count_vec[vec[i]]++;
  }
  ll piv = 0;
  ll cou = 0;
  while(1){
    if(cou == n){
      break;
    }
    if(count_vec[piv]){
      count_vec[piv]--;
      cout << piv;
      cou++;
      if(cou != n){
        cout << " ";
      }
    }else{
      piv++;
    }
  }
  cout << endl;
}
int main(){
  ll n;
  cin >> n;
  vector<ll> vec(n);
  rep(i,n){
    cin >> vec[i];
  }
  countingSort(vec,n);
}


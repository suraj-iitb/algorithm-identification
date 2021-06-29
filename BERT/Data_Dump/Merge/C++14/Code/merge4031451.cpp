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
ll ans;
void merge(vector<ll>&A,ll left,ll mid,ll right){
  ll n1 = mid - left;
  ll n2 = right - mid;
  vector<ll> L(n1+1),R(n2+1);
  rep(i,n1){
    L[i] = A[left+i];
  }
  rep(i,n2){
    R[i] = A[mid+i];
  }
  L[n1] = INFLONG;
  R[n2] = INFLONG;
  ll i = 0;
  ll j = 0;
  for(ll k = left;k < right;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
    ans++;
  }
}

void mergeSort(vector<ll> &vec, ll left, ll right){
//  rep(i,10){
//    cout << vec[i];
//    if(i != 10-1){
//      cout << " ";
//    }
//  }
  //cout << endl;
  if(left+1 < right){
    ll mid = (left+right) / 2;
    mergeSort(vec,left,mid);
    mergeSort(vec,mid,right);
    merge(vec,left,mid,right);
  }
}

int main(){
  ll n;
  cin >> n;
  vector<ll> vec(n);
  rep(i,n){
    cin >> vec[i];
  }
  ans = 0;
  mergeSort(vec,0,n);
  rep(i,n){
    cout << vec[i];
    if(i != n-1){
      cout << " ";
    }
  }
  cout << endl;
  cout << ans << endl;

  return 0;
}


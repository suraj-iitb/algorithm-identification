#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define FOR(i,m,n) for(ll i=(m); (i)<(n); ++(i))
#define REP(i,n) FOR(i,0,n)
#define INFTY 10000000000

ll cnt = 0;

void merge(vector<ll> &a, const ll left, const ll mid, const ll right){
  ll n1 = mid - left;
  ll n2 = right - mid;
  vector<ll> L(n1+1), R(n2+1);
  REP(i,n1) L[i] = a[left+i];
  REP(i,n2) R[i] = a[mid+i];
  L[n1] = INFTY, R[n2] = INFTY;
  ll i = 0, j = 0;
  FOR(k,left,right){
    ++cnt;
    if(L[i] <= R[j]){
      a[k] = L[i];
      ++i;
    }
    else{
      a[k] = R[j];
      ++j;
    }
  }
}

void mergeSort(vector<ll> &a, const ll left, const ll right){
  if(left+1 < right){
    ll mid = (left+right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  ll n; cin >> n;
  vector<ll> a(n); REP(i,n) cin >> a[i];
  mergeSort(a, 0, n);
  REP(i,n-1) cout << a[i] << " ";
  cout << a[n-1] << "\n";
  cout << cnt << "\n";
  return 0;
}

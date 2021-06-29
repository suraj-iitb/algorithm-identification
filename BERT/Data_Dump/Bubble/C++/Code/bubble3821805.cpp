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
const ll mod = 1e9+7;
const int INF = 1e9;
const ll INFLONG = 1e18;
void swap(ll *a,ll *b){
  ll tmp = *a;
  *a = *b;
  *b = tmp;
}
ll bubbleSort(vector<ll> vec,ll n){
  ll sum = 0;
  for(ll i = 0;i < n-1;i++){
    for(ll j = 0;j < n-1-i;j++){
      if(vec[j] > vec[j+1]){
        sum ++;
        swap(&vec[j],&vec[j+1]);
      }
    }
  }
  rep(i,n){
    if(i != n-1){
      cout << vec[i] << " ";
    }else{
      cout << vec[i];
    }
  }
  cout << endl;
  return sum;
}
int main(){
  ll n;
  cin >> n;
  vector<ll> vec(n);
  rep(i,n){
    cin >> vec[i];
  }
  ll ans = bubbleSort(vec,n);
  cout << ans << endl;
}


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
ll tmp1,tmp2;
void insertionSort(ll A[],ll N){
  for(ll i = 1;i< N;i++){
    ll v = A[i];
    ll j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    rep(j,N){
      if(j == N-1){
        cout << A[j];
      }else{
        cout << A[j] << " ";
      }
    }
    cout << endl;
  }
} // N個の要素を含む0-オリジンの配列A
int main(){
  ll n;
  cin >> n;
  ll a[n];
  rep(i,n){
    cin >> a[i];
  }
  rep(j,n){
    if(j == n-1){
      cout << a[j];
    }else{
      cout << a[j] << " ";
    }
  }
  cout << endl;
  insertionSort(a,n);
}



#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define REPR(i, m, n) for (int i = (int)(m); i >= (int)(n); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int n;
int a[110];

int selectionSort(int a[], int n)
{
  int cnt = 0;
  rep(i, n){
    int minj = i;
    REP(j, i, n-1){
      if(a[j] < a[minj]){
        minj = j;
      }
    }
    if(minj != i){
      swap(a[i], a[minj]);
      cnt++;
    }
  }
  return cnt;
}

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  
  int ans = selectionSort(a, n);

  rep(i, n){
    if(i>0) cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << ans << endl;

  return 0;
}



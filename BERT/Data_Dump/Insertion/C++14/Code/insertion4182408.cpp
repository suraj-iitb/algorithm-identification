#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int n;
int a[1100];

void insertionSort(int a[], int n)
{
  rep(i, n){
    int v = a[i];
    int j = i-1;
    while(0<=j && v<a[j]){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    rep(j, n){
      if(j!=n-1) cout << a[j] << " ";
      else cout << a[j];
    }
    cout << endl;
  }
}

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];

  insertionSort(a, n);

  return 0;
}








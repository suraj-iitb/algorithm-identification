#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

void selectionsort(vi a, int n, int cnt){
  for(int i=0; i<n; i++){
    int minj=i;
    for(int j=i; j<n; j++){
      if(a[j]<a[minj])minj=j;
    }
    if(a[i]!=a[minj]){
      int x=a[i], y=a[minj];
      a[i]=y;
      a[minj]=x;
       cnt++;
    }
  }
  rep(i, n-1)cout << a[i] << " ";
  cout << a[n-1] << endl << cnt << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, cnt=0, i, j;
  cin >> n;
  vi a(n);
  rep(i, n)cin >> a[i];
  selectionsort(a, n, cnt);

  return 0;
}

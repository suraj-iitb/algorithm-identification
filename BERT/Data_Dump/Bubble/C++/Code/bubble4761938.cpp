#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

void bubblesort(vi a, int n){
  int cnt=0;
  bool flag=1;
  while(flag){
    flag=0;
    for(int j=n-1; j>0; j--){
      if(a[j]<a[j-1]){
        int x=a[j], y=a[j-1];
        a[j]=y;
        a[j-1]=x;
        flag=1;
        cnt++;
      }
    }
  }
  rep(i, n-1)cout << a[i] << " ";
  cout << a[n-1] << endl << cnt << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vi a(n);
  rep(i ,n)cin >> a[i];

  bubblesort(a, n);

  return 0;
}

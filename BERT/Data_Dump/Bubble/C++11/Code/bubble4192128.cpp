#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (n); i++)
#define rrep(i, s, n) for (int i = (s); i > (n); i--)
#define all(v) v.begin(), v.end()
#define out(s) cout << (s) << endl
#define ll long long

void solve(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,0,n){cin>>a[i];}

  int ans = 0;
  rep(i,0,n){
    rrep(j,n-1,i){
      if(a[j-1]>a[j]){
        swap(a[j-1],a[j]);
        ans++;
      }
    }
  }

  rep(i,0,n){
    cout<<a[i];
    if(i!=n-1)
    {
        cout<<" ";
    }
  }
  cout<<endl;
  out(ans);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}


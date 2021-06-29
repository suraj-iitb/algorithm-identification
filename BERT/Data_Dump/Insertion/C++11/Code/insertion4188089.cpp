#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()
#define out(s) cout << (s) << endl
#define ll long long

string join(vector<int> v, string sep){
  std::stringstream ss;
  for(size_t i = 0; i < v.size(); ++i){
    if(i != 0)
    ss << sep;
    ss << v[i];
  }
  return ss.str();
}

void solve(){
  int n;
  cin>>n;
  vector<int> A(n);
  rep(i,0,n) {cin>>A[i];}

  out(join(A, " "));

  rep(i,1,n){
    int v = A[i];
    int j=i-1;
    while(j>=0&&A[j]>v){
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=v;
    out(join(A, " "));
  }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}


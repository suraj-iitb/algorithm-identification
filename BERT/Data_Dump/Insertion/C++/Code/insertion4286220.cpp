#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1; i<n; i++)
int main()
{
  int n; cin>>n;
  vector<int>v(n+1);
  rep(i,n+1) cin>>v[i];
  rep(i,n+1)
  {
    int key = v[i];
    int j = i - 1;
    while (j >= 0 && v[j] > key)
    {
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = key;
    rep(k,n+1)
    {
      cout << v[k];
      k==n ? cout << "\n" : cout << " ";
    }
  }
}

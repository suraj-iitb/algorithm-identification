#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807

void warshallfloyd(vector< vector <ll> > &d)
{
for (int k = 0; k < d.size(); k++)
  for (int i = 0; i < d.size(); i++)
    for (int j = 0; j < d.size(); j++)
      d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
ll n;
ll m;
cin >> n >> m;
vector<vector<ll>> d(n, vector<ll>(n, INF));
rep(i, n) { d[i][i] = 0; }
rep(i, m)
{
  ll a, b, c;
  cin >> a >> b >> c;
  d[a][b] = c;
}
warshallfloyd(d);
rep(i, n) if (d[i][i] < 0)
{
  cout << "NEGATIVE CYCLE" << endl;
  return 0;
}
for (int i = 0; i < n; ++i)
{
  for (int j = 0; j < n; ++j)
  {
    if(j>0)cout << " " ;
    ll num = d[i][j];
    if (num <= INF / 2)
      cout << num ;
    else
      cout << "INF" ;
  }
  cout << endl;
}

return 0;
}


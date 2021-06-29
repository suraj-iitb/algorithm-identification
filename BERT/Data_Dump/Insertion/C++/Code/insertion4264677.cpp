#include <bits/stdc++.h>
using namespace std;
#define ul unsigned long long
#define ll long long
#define ld long double


int main()
{
  ll n;
  cin >>n;

  ll a[100];
  for (ll i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  for (ll k = 0; k < n - 1; k++)
  {
    cout << a[k] << " ";
  }
  cout << a[n - 1] << endl;

  ll v,j;
  for (ll i = 1; i < n; i++)
  {
    v=a[i];
    j=i-1;
    while (j>=0&&a[j]>v) {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;

    for (ll k = 0; k < n-1; k++)
    {
      cout<<a[k]<<" ";
    }
    cout<<a[n-1]<<endl;

  }
  

  return 0;
}


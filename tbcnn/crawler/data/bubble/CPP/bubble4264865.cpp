#include <bits/stdc++.h>
using namespace std;
#define ul unsigned long long
#define ll long long
#define ld long double



int main()
{
  ll n,a[100];
  cin>>n;
  for (ll i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  ll f=1,ct=0;
  while (f) {
    f=0;
    for (ll j = n-1; j >0 ;j--) {
      if (a[j]<a[j-1]) {
        swap(a[j],a[j-1]);
        ct++;
        f=1;
      }
    }
  }
  for (ll i = 0; i < n-1; i++)
  {
    cout << a[i] << " ";
  }
  cout << a[n-1] <<endl;

  cout<<ct<<endl;

  return 0;
}


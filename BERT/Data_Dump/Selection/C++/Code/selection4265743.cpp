#include "bits/stdc++.h"
using namespace std;

#define ul unsigned long long
#define ll long long


int main()
{
  ll n,a[100];
  cin>>n;
  for (ll i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  ll minj,ct=0;
  for (ll i = 0; i < n; i++)
  {
    minj=i;
    for (ll j = i; j < n; j++)
    {
      if (a[j]<a[minj]) minj=j;
    }
    swap(a[i],a[minj]);
    ct+= i!=minj;
  }
  for (ll i = 0; i < n; i++)
  {
    if (i<n-1) cout<<a[i]<<" ";
    else cout<<a[i]<<endl;
  }
  cout<<ct<<endl;

  return 0;
}


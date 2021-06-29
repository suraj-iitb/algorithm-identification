#include <bits/stdc++.h>
using namespace std;



typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;
typedef pair<ll, ll> pint;


#define rep(i,n) for(ll i=0;i<n;i++)



void print(const vint& v)
{
  for(int i=0; i+1<v.size(); ++i){
    std::cout << v[i] << " ";
  }
  cout<<v.back()<<endl;
}

ll selectionSort(vint &a){
  ll n = a.size();
  ll cnt = 0;

  rep(i, n){
    ll minj = i;
    for(ll j=i; j<n; ++j){
      if(a[j] < a[minj]){
        minj = j;
      }
    }
    swap(a[i], a[minj]);
    cnt += i!=minj;
  }

  return cnt;
}

int main() {


  cout<<fixed<<setprecision(10);

  ll n; cin>>n;
  vint a(n); rep(i,n) cin>>a[i];

  ll cnt = selectionSort(a);
  print(a);
  cout<<cnt<<endl;


}





//



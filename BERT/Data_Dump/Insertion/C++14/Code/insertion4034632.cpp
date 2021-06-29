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
  std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
}

void insertionSort(vint &A){
  for(ll i=1; i<A.size(); ++i){
    rep(k,A.size()-1) cout<<A[k]<<" ";
    cout<<A.back()<<endl;
    ll v = A[i];
    ll j = i - 1;
    while( j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
}

int main() {


  cout<<fixed<<setprecision(10);

  ll n; cin>>n;
  vint v(n);rep(i,n)cin>>v[i];

  insertionSort(v);
  rep(k,v.size()-1) cout<<v[k]<<" ";
  cout<<v.back()<<endl;
}





//



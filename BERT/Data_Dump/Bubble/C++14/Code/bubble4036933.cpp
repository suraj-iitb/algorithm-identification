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
  // std::for_each(v.begin(), v.end()-1, [](int x) {
  //   std::cout << x << " ";
  // });
  // std::cout << std::endl;
}

ll bubbleSort(vint &a){
  ll cnt = 0;
  ll n = a.size();

  bool f = true;
  while(f){
    f = false;
    for(ll j=n-1; j>0; j--){
      if(a[j] < a[j-1]) {swap(a[j], a[j-1]); f = true; cnt++;}
    }
  }


  return cnt;
}

int main() {


  cout<<fixed<<setprecision(10);

  ll n; cin>>n;
  vint a(n); rep(i,n) cin>>a[i];

  ll cnt = bubbleSort(a);
  print(a);
  cout<<cnt<<endl;


}





//



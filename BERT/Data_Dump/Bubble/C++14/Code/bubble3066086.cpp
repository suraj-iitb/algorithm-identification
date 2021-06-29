#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll bit_size(ll a){
  for(int i=0;i<63;i++){
    if(1<<i >= a){return i;}
  }
  return 63;
}

//1-index
template<typename T>
class BIT{
private:
  vector<T> bit;
  ll size;

public:
  BIT(vector<T> t){
    size=bit_size(t.size());
    bit.resize((1<<size)+1,0);
    for(int i=1;i<=t.size();i++){
      change(i,t[i-1]);
    }
  }

  BIT(ll s){
    size=bit_size(s);
    bit.resize((1<<size)+1);
  }

  BIT(ll s,T a){
    size=bit_size(s);
    bit.resize((1<<size)+1,a);
  }

  void add(ll where,T a){
    while(where<bit.size()){
      bit[where]+=a;
      where+=where&-where;
    }
  }

  //[1,r]
  T sum(ll r){
    T ret=0;
    while(r>0){
      ret+=bit[r];
      r=r&(r-1);
    }
    return ret;
  }

  //[l,r]
  T sum(ll l,ll r){
    T ret=sum(r);
    ret-=sum(l-1);
    return ret;
  }
};




int main(){
  ll n;
  cin>>n;
  vector<ll> a;
  for(int i=0;i<n;i++){
    ll b;
    cin>>b; b++;
    a.push_back(b);
  }
  ll ans=0;
  BIT<ll> b(120,0);
  for(int i=0;i<n;i++){
    b.add(120-a[i],1);
    ans+=b.sum(120-a[i]-1);
  }
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    a[i]--;
    cout<<a[i];
    if(i!=n-1){cout<<" ";}
  }
  cout<<endl<<ans<<endl;







  return 0;
}


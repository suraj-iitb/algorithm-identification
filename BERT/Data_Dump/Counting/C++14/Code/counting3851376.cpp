#include"bits/stdc++.h"
using namespace std;
using ll=long long;
using ull=unsigned long long;
constexpr auto inf=static_cast<ll>(1e18);
template<typename T=ll>inline T in(){T ret;cin>>ret;return ret;}
template<typename T=ll>inline auto vec2(size_t h,size_t w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}
inline void setp(int n){cout<<fixed<<setprecision(n);}
inline void delnl(){cin.ignore(numeric_limits<streamsize>::max(),'\n');}

int main()
{
    ll n=in(),k=-1;vector<ll>a(n),b(n),c(10001,0);
    for(ll i=0;i<n;++i){
        ++c[a[i]=in()];
        k=max(k,a[i]);
    }
    for(ll i=0;i<k;++i)c[i+1]+=c[i];
    for(ll i=n-1;i>=0;--i)b[--c[a[i]]]=a[i];
    for(ll i=0;i<n;++i){
        if(i!=0)cout<<' ';
        cout<<b[i];
    }
    cout<<endl;
}

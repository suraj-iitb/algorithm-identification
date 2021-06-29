#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//pow(llpow,modpow)
template<class T> ll llpow(ll x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
long long modpow(long long a, long long n, long long mod) {long long res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
//最大公約数
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
//最小公倍数
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}
//逆元
long long modinv(long long a, long long m) {long long b = m, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}

#define rep(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)

long long INF = 1LL<<60;
int a[100];

template<class T> void printvec(T a[],int size){
    for(int i=0;i<size-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[size-1]<<endl;
}

//挿入ソート(昇順0,降順1)
template<class T> int insertion_sort(T a[],int size,int which){
    if(which!=0&&which!=1)return -1;
        for(int i=1;i<size;i++){
        T v=a[i];
        int p=i-1;
        if(which==0){
            while(a[p]>v&&p>=0){
                a[p+1]=a[p];
                p--;
            }
        }
        else{
            while(a[p]<v&&p>=0){
                a[p+1]=a[p];
                p--;
            }
        }
        a[p+1]=v;
        printvec(a,size);
        }
    return 0;
}
int main( ){
    int n;
    cin>>n;
    rep(i,0,n)cin>>a[i];
    printvec(a,n);
    insertion_sort(a,n,0);
    return 0;
}




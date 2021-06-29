#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

void show(vector<ll> &A){
    for(int i=0;i<A.size();i++){
        cout<<A[i];
        if(i+1!=A.size()){cout<<" ";}
    }
    cout<<endl;
}


int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    show(a);
    for(int i=1;i<n;i++){
        ll key=a[i];
        for(int t=i-1;t>=0;t--){
            if(a[t]>a[t+1]){swap(a[t],a[t+1]);}
        }
        show(a);
    }
    
    
    
    return 0;
}


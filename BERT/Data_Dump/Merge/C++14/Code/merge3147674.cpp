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




ll merge(vector<ll> &A,ll left,ll mid,ll right){
    ll n1 = mid - left;
    ll n2 = right - mid;
    vector<ll> L(n1+1,E),R(n2+1,E);
    ll count=0;
    for(int i=0;i<n1;i++){
        L[i] = A[left + i];
    }
    for(int i=0;i<n2;i++){
        R[i] = A[mid + i];
    }
    ll i = 0;
    ll j = 0;
    for(ll k=left;k<right;k++){
        count++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
    return count;
}

ll mergeSort(vector<ll> &A,ll left,ll right){
    ll count=0;
    if( left+1 < right){
        ll mid = (left + right)/2;
        count+=mergeSort(A, left, mid);
        count+=mergeSort(A, mid, right);
        count+=merge(A, left, mid, right);
    }
    return count;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    ll count=mergeSort(a,0,a.size());
    for(int i=0;i<n;i++){cout<<a[i]; if(i!=n-1){cout<<" ";}}
    cout<<endl<<count<<endl;
    return 0;
}


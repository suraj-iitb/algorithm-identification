#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

ll a[1000000];
ll L[1000000],R[1000000];
int ans = 0;

void merge(ll n,ll left,ll right,ll mid){
    ll n1 = mid - left;
    ll n2 = right - mid;
    for(int i = 0;i < n1;i++){
        L[i] = a[left+i];
    }
    for(int i = 0;i < n2;i++){
        R[i] = a[mid+i];
    }
    L[n1] = R[n2] = 5000000000;
    int i = 0,j = 0;
    for(ll k = left;k < right;k++){
        if(L[i] < R[j]){
            a[k] = L[i];
            i++;
            ans++;
        }else{
            a[k] = R[j];
            j++;
            ans++;
        }
    }
}

void mergesort(ll n,ll left,ll right){
    if(left + 1 < right){
        ll mid = (left + right) / 2;
        mergesort(n,left,mid);
        mergesort(n,mid,right);
        merge(n,left,right,mid);
    }
}


int main() {
    ll n; cin >> n; for(int i = 0;i < n;i++) cin >> a[i];
    mergesort(n,0,n);
    for(int i = 0;i < n;i++){
        if(i < n-1){
            cout << a[i] << " ";
        }else{
            cout << a[i] << endl;
            cout << ans << endl;
        }
    }
}



#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 2001001;

vector<int> a(MAX_N),b(MAX_N),c(MAX_N);
int n;

void CoutingSort(vector<int> a,vector<int> b,int k){
    rep(i,k+1) c[i] = 0;
    for(int i=1;i<=n;i++) c[ a[i] ]++;
    for(int i=1;i<=k;i++) c[i] = c[i] + c[i-1];
    for(int i=n;i>=1;i--){
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    rep(i,n) if(i!=0) cout << b[i] << " ";
    cout << b[n]<< endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int mx = 0;
    rep(i,n) cin >> a[i+1],mx = max(mx,a[i]);
    CoutingSort(a,b,mx);

    return 0;
}


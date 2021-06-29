#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define rep1(i,n) for(int i=1 ; i<=n ; i++)
#define vi vector<int>
#define vii vector<int,int>
#define Sort(v) sort(v.begin(),v.end())
#define Reverse(v) reverse(v.begin(),v.end())

//const int MOD = 1000000007;
//const int INF = 1<<30;
using namespace std;

string disp(bool x){
    return x ? "Yes" : "No";
}


int main(){
    int n; cin >> n;
    
    int a[n];
    rep(i,n) cin >> a[i];
    rep(i,n) cout << a[i] << ((i == n-1) ? '\n':' ');
    
    for(int i=1;i<=n-1;i++){
        int v = a[i];
        int j = i-1;
        
        while(j>=0 and a[j]>v){
            a[j+1] = a[j];
            j--;
            a[j+1] = v;
        }
        rep(i,n) cout << a[i] << ((i == n-1) ? '\n':' ');
    }
}
    
    






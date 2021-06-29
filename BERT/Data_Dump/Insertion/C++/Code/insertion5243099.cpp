#include <bits/stdc++.h>
#include <cmath>
#include<algorithm>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;
double pi = 3.141592653589793238;


int main() {
    int n ; 
    cin >> n ; 
    vector<int> a(n) ; 
    rep(i,n) cin >> a.at(i) ; 
    
    for(int i=1;i<n;i++){
       rep(i,n){
            cout << a.at(i) ; 
            if(i==n-1)cout << endl ; 
            else      cout << " " ; 
        }
        int v = a.at(i) ; 
        int j = i-1 ; 
        while(j>=0 && a.at(j) > v ){
            a.at(j+1) = a.at(j) ;  
            j -- ; 
            a.at(j+1) = v ; 
        }
    }

  rep(i,n){
            cout << a.at(i) ; 
            if(i==n-1)cout << endl ; 
            else      cout << " " ; 
        }

}


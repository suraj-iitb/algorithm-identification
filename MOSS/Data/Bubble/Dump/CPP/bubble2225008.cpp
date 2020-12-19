#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#define rep(i,a,b) for(int (i)=(a);i<(b);i++)
#define INF 1000000000
#define MAX_N 150005
using namespace std;

int dp[10005][10005];

int main(){
    int n,a[101];
    cin>>n;
    rep(i,0,n)cin>>a[i];
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                cnt++;
            }
        }
        
    }
    rep(i,0,n){
        cout<<a[i];
        if(i==n-1)cout<<endl;
        else cout<<" ";
    }
    cout<<cnt<<endl;
    return 0;
}

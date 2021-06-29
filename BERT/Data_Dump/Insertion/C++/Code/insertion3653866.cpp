#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    REP(i,n)cin>>a[i];
    REP(j,n){if(j!=0)cout<<" ";cout<<a[j];}cout<<endl;
    rep(i,1,n)
    {
        int now=i;
        int front=i-1;
        while(a[front]>a[now]&&front>=0)
        {
            swap(a[front],a[now]);
            now--;
            front--;
            
        }
        REP(j,n){if(j!=0)cout<<" ";cout<<a[j];}cout<<endl;
    }
}


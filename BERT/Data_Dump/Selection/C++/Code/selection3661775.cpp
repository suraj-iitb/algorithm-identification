#include <bits/stdc++.h>
#define rep(i,a,b) for (int64_t i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;

int main()
{
    int n,sum=0;cin>>n;
    int a[n];REP(i,n)cin>>a[i];


    REP(i,n)
    {
        int mn=i;
        rep(j,i,n)
        {
            if(a[j]<a[mn])
            mn=j;
        }
        if(a[mn]!=a[i]){swap(a[mn],a[i]);sum++;}
    }

    REP(i,n)
    {
        if(i!=0)cout<<" ";
        cout<<a[i];
    }cout<<endl;
    cout<<sum<<endl;
}


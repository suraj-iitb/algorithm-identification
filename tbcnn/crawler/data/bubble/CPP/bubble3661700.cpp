#include <bits/stdc++.h>
#define rep(i,a,b) for (int64_t i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;

int main()
{
    int n,sum=0;
    cin>>n;
    int a[n];
    REP(i,n)cin>>a[i];
    bool flag=1;
    while(flag)
    {
        
        flag=0;
        for(int i=n-1;i>0;i--)
        {
            if(a[i]<a[i-1])
            {
                swap(a[i],a[i-1]);
                flag=1;
                sum++;
            }
        }
    }
    REP(i,n)
    {
        if(i!=0)cout<<" ";
        cout<<a[i];
    }cout<<endl;
    cout<<sum<<endl;
}


#include<bits/stdc++.h>
#define MAXN 10000005
using namespace std;
typedef unsigned long long ull;
int a[MAXN];
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int t=i;
        for(int j=t;j<n;j++)
            if(a[j]<a[t])
                t=j;
        if(i!=t)
        {
            ans++;
            swap(a[i],a[t]);
        }
    }
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<' ';
    cout<<a[n-1]<<endl<<ans<<endl;
}


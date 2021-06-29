#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main()
{
    //freopen("inp.txt","r",stdin);
    //freopen("outp.txt","w",stdout);
    int n,k=-1;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n; i++)
    {
        cin>>a[i];
        k=max(k,a[i]);
    }
    /*for(int i=0;i<=k;i++)
        c[i]=0;

    for(int j=1;j<=n;j++)
        c[a[j]]=c[a[j]]+1;

    for(int i=1;i<=k;i++)
        c[i]=c[i]+c[i-1];

    for(int j=n;j>=1;j--)
    {
        b[c[a[j]]]=a[j];
        c[a[j]]=c[a[j]]-1;
    }*/
    sort(a,a+n);

    for(int i=0;i<n;i++)
    {
        if(i==0)
            cout<<a[i];
        else
            cout<<" "<<a[i];
    }
    cout<<"\n";
    return 0;
}


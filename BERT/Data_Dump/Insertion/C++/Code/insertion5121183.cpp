#include <bits/stdc++.h>

using namespace std;

int a[11000];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        for(int q=1;q<=n;q++)
        {
            if(q!=n)
                cout<<a[q]<<' ';
            else
                cout<<a[q]<<'\n';
        }
        for(int j=i-1;j>=1;j--)
        {

            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
            else
                break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=n)
            cout<<a[i]<<' ';
        else
            cout<<a[i]<<'\n';
    }
    return 0;
}


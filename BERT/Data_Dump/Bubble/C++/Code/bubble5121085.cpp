#include <bits/stdc++.h>

using namespace std;
int a[110000] ;

int main()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        bool change = false;

        for(int j=1;j<=n-i;j++)
        {

            if(a[j]>a[j+1])
            {
                ///for(int i=1;i<=n;i++)
                ///    cout<<a[i]<<' ';
                ///cout<<endl;
                /// a[j] ba a[j+1] avaz mikone
                swap(a[j],a[j+1]);
                change = true;
                ans++;

            }
        }
        if(change == false)
            break;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=n)
            cout<<a[i]<<' ';
        else
            cout<<a[i]<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}


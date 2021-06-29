#include <bits/stdc++.h>

using namespace std;
int a[111];
int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
          for(int i=1;i<=n;i++)

            if(i!=n)
                cout<<a[i]<<' ';
            else
                cout<<a[i]<<'\n';
    }
    return 0;
}


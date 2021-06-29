#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[105];
    int ans = 0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int flag = 1;
    for(int i=0;flag;i++)
    {
        flag = 0;
        for(int j=n-1;j>=i+1;j--)
        {
            if(a[j]<a[j-1])
            {
                int m = a[j-1];
                a[j-1] = a[j];
                a[j] = m;
                flag = 1;
                ans++;
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    cout<<ans<<endl;

    return 0;
}


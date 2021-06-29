#include<iostream>
using namespace std;
int a[105];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                ans++;
            }
    }
    for(int i=0;i<n;i++)
    {
        if(i)cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}


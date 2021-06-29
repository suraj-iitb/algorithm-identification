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
    for(int i=0;i<n;i++)
    {
        int mini = i;
        int flag = 0;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[mini])
            {
                flag = 1;
                mini = j;
            }
        }
        swap(a[i], a[mini]);
        if(flag) ans++;

    }
    for(int i=0;i<n-1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    cout<<ans<<endl;

    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int cnt=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-1;i++)
        for(int j=n-1;j>=i+1;j--)
        if(a[j]<a[j-1])
        swap(a[j],a[j-1]),cnt++;
    for(int i=0;i<n;i++)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<"\n";
    cout<<cnt<<"\n";
return 0;
}


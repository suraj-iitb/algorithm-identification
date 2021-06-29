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
        for(int i=0;i<n-1;i++)
            cout<<a[i]<<' ';
        cout<<a[n-1]<<endl;
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key)
            a[j+1]=a[j],j--;
        a[j+1]=key;
        for(int i=0;i<n-1;i++)
            cout<<a[i]<<' ';
        cout<<a[n-1]<<endl;
    }
}


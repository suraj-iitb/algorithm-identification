#include<bits/stdc++.h>
#define MAXN 10000005
using namespace std;
typedef unsigned long long ull;
int a[MAXN];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=1; j<n-i; j++)
            if(a[j]<a[j-1])
            {
                swap(a[j-1],a[j]);
                ans++;
            }
    for(int i=0; i<n-1; i++)
        cout<<a[i]<<' ';
    cout<<a[n-1];
    cout<<endl<<ans<<endl;
}

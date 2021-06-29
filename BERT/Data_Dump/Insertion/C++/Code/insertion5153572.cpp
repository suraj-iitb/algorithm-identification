#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[101],x,y;
    cin>>n;
    for(x=0;x<n;x++)
        cin>>a[x];
    for(x=0;x<n;x++)
    {
        sort(a,a+x+1);
        for(y=0;y<n-1;y++)
            cout<<a[y]<<" ";
        cout<<a[y]<<endl;
    }
    return 0;
}

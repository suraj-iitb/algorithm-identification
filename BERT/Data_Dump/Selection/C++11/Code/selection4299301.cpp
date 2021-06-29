#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll a,i,temp,j,c=0,m;
    cin>>a;
    ll b[a];
    for(i=0;i<a;i++)
    {
        cin>>b[i];
    }
    for(i=0;i<a;i++)
    {
        m=i;
        for(j=i;j<a;j++)
        {
            if(b[j]<b[m])
            {
                m=j;
            }
        }
        if(m!=i)
        {
            c++;
            temp = b[i];
            b[i]=b[m];
            b[m]=temp;
        }
    }
    for(i=0;i<a;i++)
    {
        if(i==a-1)
            cout<<b[i]<<endl;
        else
        cout<<b[i]<<" ";
    }
    cout<<c<<endl;
}


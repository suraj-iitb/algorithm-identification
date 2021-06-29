#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll a,i,temp,j,c=0;
    cin>>a;
    ll b[a];
    for(i=0;i<a;i++)
    {
        cin>>b[i];
    }
    for(i=0;i<a;i++)
    {
        for(j=a-1;j>i;j--)
        {
            if(b[j]<b[j-1])
            {
                c++;
                temp = b[j];
                b[j]=b[j-1];
                b[j-1]=temp;
            }
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

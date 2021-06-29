#include <bits/stdc++.h>
using namespace std;
int tag[100000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tag[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(tag[j]<tag[j-1])
            {
                swap(tag[j],tag[j-1]);
                sum++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i)cout<<' ';
        cout<<tag[i];
    }
    cout<<endl;
    cout<<sum<<endl;


}

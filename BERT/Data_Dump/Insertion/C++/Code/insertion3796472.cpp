#include<iostream>
using namespace std;
int  a[10005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(i)cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
    for(int i=1;i<n;i++)
    {
        int v=a[i];
        int j=i-1;
        while(j>=0&&a[j]>v)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        for(int k=0;k<n;k++)
        {
            if(k)cout<<' ';
            cout<<a[k];
        }
        cout<<endl;
    }

    return 0;
}


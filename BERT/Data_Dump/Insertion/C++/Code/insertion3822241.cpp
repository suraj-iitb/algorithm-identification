#include <bits/stdc++.h>
using namespace std;

void show(int n,int a[])
{
    for(int i=0;i<n;i++)
    {
        if(i>0)cout<<" "<<a[i];
        else cout<<a[i];
    }
    cout<<endl;
}

void insertion(int n,int a[])
{
    int i,j,v;
    for(int i=1;i<n;i++)
    {
        j=i-1;
        v=a[i];
        while(j>=0&&v<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        show(n,a);
    }
     
}

int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    show(n,a);
    insertion(n,a);
    return 0;
}

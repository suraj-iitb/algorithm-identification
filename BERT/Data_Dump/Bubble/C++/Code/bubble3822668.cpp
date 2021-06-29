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

int bubble(int n,int a[])
{
    int sw=0;
    bool flag=1;
    for(int i=0;flag;i++)
    {
        flag=0;
        for(int j=n-1;j>=i+1;j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
                sw +=1;
                flag = 1;
            }
        }
    }
    show(n,a);
    return sw;
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
    int sw = bubble(n,a);
    cout<<sw<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int bubbleSort(int a[],int n)
{
    int sum=0;
    bool flog=1;
    for(int i=0;flog;i++)
    {
        flog=0;
        for(int j=n-1;j>=i+1;j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
                flog=1;
                sum++;
            }
        }
    }
    return sum;
}
int main()
{
    int n,sum;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sum=bubbleSort(a,n);
    for(int i=0;i<n;i++)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<sum<<endl;
}

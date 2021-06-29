#include<bits/stdc++.h>
using namespace std;
int selectionsort(int a[],int n)
{
    int i,j,mini,temp,count=0;
    for(i=0;i<n-1;i++)
    {
        mini=i;
        for(j=i;j<n;j++)
        {
            if(a[j]<a[mini])
                mini=j;
        }
            temp=a[i];
            a[i]=a[mini];
            a[mini]=temp;
            if(i!=mini) count++;
    }
    return count;
}
int main()
{
    int a[100],n,i,count;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    count=selectionsort(a,n);
    for(i=0;i<n;i++)
    {
        if(i>0&&i!=n)cout<<" ";
        cout<<a[i];
    }
        cout<<endl;
        cout<<count<<endl;
}


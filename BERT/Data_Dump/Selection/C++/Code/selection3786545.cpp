#include<bits/stdc++.h>
using namespace std;
int selectionSort(int a[],int n)
{
    int i,j,t,sum=0,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        if(i!=min)
        {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
            sum++;
        }
    }
    return sum;
}
int main()
{
    int a[100],n,i,sum;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sum=selectionSort(a,n);
    for(i=0;i<n;i++)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<sum<<endl;
    return 0;
}

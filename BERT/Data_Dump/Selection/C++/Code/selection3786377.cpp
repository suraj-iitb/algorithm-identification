#include<bits/stdc++.h>
using namespace std;
int selectionSort(int a[],int n)
{
    int i,j,t,sw=0,minj;
    for(i=0;i<n-1;i++)
    {
        minj=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[minj])
                minj=j;
        }
        t=a[i];
        a[i]=a[minj];
        a[minj]=t;
        if(i!=minj)
            sw++;
    }
    return sw;
}
int main()
{
    int a[100],n,i,sw;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sw=selectionSort(a,n);
    for(i=0;i<n;i++)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<sw<<endl;
    return 0;
}

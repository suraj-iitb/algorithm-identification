#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int n,i,j,temp,count=0;cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                count++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(i>0&&i!=n)
        cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<count<<endl;
    return 0;
}


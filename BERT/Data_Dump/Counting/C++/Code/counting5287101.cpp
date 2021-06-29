#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n], max_v=0;
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
        if(i==0)
        {
            max_v=ar[i];
        }
        else
        {
            if(max_v<ar[i])
            {
                max_v=ar[i];
            }
        }
    }
    int temp[max_v+5], sorted[n+5];
    for(int i=0; i<=max_v; i++)
    {
        temp[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        temp[ar[i]]++;
    }
    for(int i=1; i<=max_v; i++)
    {
        temp[i]=temp[i]+temp[i-1];
//        if(i==0)
//        {
//            temp1[i]=temp[i];
//        }
//        else
//        {
//            temp1[i]=(temp1[i-1]+temp[i]);
//        }
    }
    for(int i=n-1; i>=0; i--)
    {
        sorted[temp[ar[i]]]=ar[i];
        temp[ar[i]]--;
    }
    for(int i=1; i<=n; i++)
    {
        if(i==1)
        {
        cout<<sorted[i];
        }
        else
        {
        cout<<" "<<sorted[i];
        }
    }
    cout<<endl;

}


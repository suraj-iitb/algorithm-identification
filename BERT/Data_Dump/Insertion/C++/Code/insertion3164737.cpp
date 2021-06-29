#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[10000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i1=0;i1<n;i1++)
        {
            if(i1<n-1)
            cout<<arr[i1]<<" ";
            else
            cout<<arr[i1];

        }
    cout<<endl;

    for(int i=1;i<n;i++)
    {
       int x=arr[i];int j=i-1;
        while(j>=0 && arr[j]>x)
        {
            arr[j+1]=arr[j];
            j--;


        }
        arr[j+1]=x;
        for(int i1=0;i1<n;i1++)
        {
            if(i1<n-1)
            cout<<arr[i1]<<" ";
            else
                cout<<arr[i1];
        }
        cout<<endl;
    }
    return 0;
}


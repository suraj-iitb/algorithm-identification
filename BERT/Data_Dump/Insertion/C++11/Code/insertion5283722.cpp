#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for(int i=0; i<n; i++)
    {
        int x=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>x)
        {
            
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=x;

        for(int k=0; k<n; k++)
        {
            cout<<arr[k];
            if((k+1)!=n)
                cout<<" ";
        }
        cout<<endl;
    }
}


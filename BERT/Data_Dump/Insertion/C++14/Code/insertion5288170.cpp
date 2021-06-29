#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        int x = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
        for(int i=0; i<n; i++)
        {
            if(i==n-1)
            {
                cout<<arr[i];
                break;
            }
            else
            {
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
}


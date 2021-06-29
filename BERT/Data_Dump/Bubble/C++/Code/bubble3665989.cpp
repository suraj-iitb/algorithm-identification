#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin>>n;
    int counter = 0;
    int track = 0;
    int arr[n];
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i = 0; i<n; i++)
    {
        counter = 0;
        for(int j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                counter = 1;
                track++;
            }
        }
        if(counter==0)
        {
            break;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(i<n-1)
        cout<<arr[i]<<" ";
        else
            cout<<arr[i];
    }
    cout<<endl;
    cout<<track<<endl;

}



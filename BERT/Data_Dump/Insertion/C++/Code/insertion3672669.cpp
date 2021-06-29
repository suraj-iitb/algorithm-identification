#include<bits/stdc++.h>
using namespace std;
int main()
{
    int size, i, j, temp;
    cin>>size;

    int arr[size];
    for(i=0; i<size; i++)
    {
        cin>>arr[i];
        if(i<size-1)
            cout<<arr[i]<<" ";
        else
            cout<<arr[i];
    }
    cout<<endl;
    for(i=1; i<size; i++)
    {
        temp=arr[i];
        j=i-1;
        while((temp<arr[j]) && (j>=0))
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
        for(int k=0; k<size; k++)
        {
            if(k<size-1)
                cout<<arr[k]<<" ";
            else
                cout<<arr[k];
        }
        cout<<endl;

    }

}


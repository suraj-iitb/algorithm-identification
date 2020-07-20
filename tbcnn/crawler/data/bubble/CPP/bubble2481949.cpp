#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++)
    {
        cin>>arr[i];
    }

    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = n-1;j >= i+1;j--)
        {
            if(arr[j] < arr[j-1])
            {
                cnt++;
                swap(arr[j], arr[j-1]);
            }
        }
    }
    
    for(int i = 0;i < n;i++)
    {
        if(i == n-1)
            cout<<arr[i];
        else
            cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<cnt<<endl;
}

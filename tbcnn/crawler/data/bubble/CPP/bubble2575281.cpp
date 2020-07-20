#include<bits/stdc++.h>
using namespace std;
int bubblesort(vector<int>&arr,int n)
{
    int swaps =0;
    for(int i=0;i<n;i++ )
    for(int j=n-1;j>=i+1;j--)
    if(arr[j]<arr[j-1])
    {
        swap(arr[j],arr[j-1]);
        swaps++;
    }
    return swaps;
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        
    }
    int swaps;
    swaps=bubblesort(arr,n);
    cout<<arr[0];
    for(int i=1;i<n;i++)
    cout<<" "<<arr[i];
    cout<<endl;
    cout<<swaps<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int bubblesort(vector<int>&a,int n)
{
    int swaps =0;
    for(int i=0;i<n;i++ )
    {
        int mini =i;
    for(int j=i+1;j<n;j++)
    {
        if(a[j]<a[mini])
        mini =j;
    }
    {
        if(mini != i)
   {        swap(a[i],a[mini]);
        swaps++;
    }}
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

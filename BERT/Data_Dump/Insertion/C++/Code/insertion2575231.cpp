#include<bits/stdc++.h>
using namespace std;
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
for(int i=0;i<n;i++)
{
    int cur = arr[i];
    int j;
    for( j=i-1;arr[j]>cur && j>=0;j--)
    {
        arr[j+1]=arr[j];
    }
    arr[j+1]=cur;
    for(int k=0;k<n;k++)
    if(k!=n-1)
    cout<<arr[k]<<" ";
    else cout<<arr[k];
    cout<<endl;
}
}

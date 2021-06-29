#include<bits/stdc++.h>
using namespace std;

void insertionsort(vector<int>a,int n)
{
    for(int i=1;i<n;i++)
    {
        int v=a[i];
        int j=i-1;
        while(j>=0&&a[j]>v)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        cout<<a[1];
        for(int j=2;j<n;j++)
            cout<<" "<<a[j];
        cout<<endl;
    }
    }
int main()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<n+1;i++)
        cin>>a[i];
    insertionsort(a,n+1);
}


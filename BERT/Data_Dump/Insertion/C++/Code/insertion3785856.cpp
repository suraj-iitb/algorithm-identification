#include <bits/stdc++.h>
using namespace std;
void trace(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if (i > 0)
            cout << " ";
        cout << a[i];
    }
    cout<<endl;
}
void insertionSort(int a[],int n)
{
    int i,j,sum;
    for(i=1;i<n;i++)
    {
        sum=a[i];
        j=i-1;
        while(j>=0&&a[j]>sum)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=sum;
        trace(a,n);
    }
}
int main()
{
    int n,i;
    cin>>n;
    int a[100];
    for(i=0;i<n;i++)
        cin>>a[i];
    trace(a,n);
    insertionSort(a,n);
    return 0;
}

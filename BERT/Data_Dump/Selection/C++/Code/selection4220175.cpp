#include <iostream>
#include <limits.h>

using namespace std;

int cnt=0;

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 1; i <=n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j <=n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(arr[min_idx],arr[i]);
        if(arr[min_idx]!=arr[i])cnt++;
    }
}

int main()
{
    int n,v[101];
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    selectionSort(v,n);
    for(int i=1;i<=n;++i)
        if(i!=n)cout<<v[i]<<" ";
        else cout<<v[i]<<endl;
    cout<<cnt<<endl;
    return 0;
}


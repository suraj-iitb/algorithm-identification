#include <bits/stdc++.h>

using namespace std;

long long int arr1[2000010];
long long int arr2[2000010];

int main()
{
    memset(arr1,0,sizeof(arr1));
    long long int n;
    cin>>n;
    long long int arr[n];
    long long int minno = 0;
    long long int maxno = 0;
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(maxno<arr[i])
        {
            maxno = arr[i];
        }
        else if(minno>arr[i])
        {
            minno = arr[i];
        }
        arr1[arr[i]]++;
    }
    for(long long int i=minno;i<maxno;i++)
    {
        arr1[i+1]+=arr1[i];
    }
    for(long long int i=0; i<n;i++)
    {
        long long int x = arr[i];
        long long int y = arr1[x];
        arr2[y] = x;
        arr1[x]--;
    }

    for(long long int i=1; i<=n; i++)
    {
        if(i!=n)
        printf("%lld ",arr2[i]);
        else
        {
            printf("%lld\n",arr2[i]);
        }
    }
}


#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n-1;i++)
        printf("%d ",arr[i]);
    printf("%d\n",arr[i]);
}
int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i = 0; i < n; ++i)
        for(int j = 0, m = n - i - 1; j < m; ++j)
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                cnt++;
            }
    print(arr,n);
    printf("%d\n",cnt);
    return 0;
}


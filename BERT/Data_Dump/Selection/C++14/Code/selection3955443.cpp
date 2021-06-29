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
    for(int i=0; i<n; i++)
    {
        int mn = arr[i],pos = i;
        for(int k=i+1; k<n; k++)
            if(mn>arr[k])
            {
                pos = k;
                mn = arr[k];
            }
        if(pos!=i)
        {
            swap(arr[pos],arr[i]);
            cnt++;
        }
    }
    print(arr,n);
    printf("%d\n",cnt);
    return 0;
}


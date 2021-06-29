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
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(arr[j-1]>arr[j])
                swap(arr[j],arr[j-1]);
        }
        print(arr,n);
    }
    return 0;
}


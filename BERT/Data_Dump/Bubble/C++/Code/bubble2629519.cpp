#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,cnt=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
     for(int i=0;i<n-1;i++)
         for(int j=0;j<n-i-1;j++)
         {
             if(arr[j]>arr[j+1])
             {
                 swap(arr[j],arr[j+1]);
                 cnt++;
             }
         }
 for(int i=0;i<n-1;i++)
    printf("%d ",arr[i]);
printf("%d\n",arr[n-1]);
 printf("%d\n",cnt);
}

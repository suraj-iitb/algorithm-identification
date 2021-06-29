
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,cnt=0,min;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
     for(int i=0;i<n-1;i++)
       {
         min=i;
         for(int j=i+1;j<n;j++)
         {
             if(arr[j]<arr[min])
             {

                 min=j;
                 //cnt++;
             }
         }
        if(i!=min)
        {swap(arr[min],arr[i]);
         cnt++;
}
         }
 for(int i=0;i<n-1;i++)
    printf("%d ",arr[i]);
printf("%d\n",arr[n-1]);
 printf("%d\n",cnt);
}

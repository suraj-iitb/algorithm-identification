#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;



int main()
{

    int n,a[100],key;
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];i==n?cout<<a[i]<<endl:cout<<a[i]<<" ";}
    for(int i=2;i<=n;i++)
       {
           int j;
         key=a[i];
         j=i-1;
         while(j>=1&&a[j]>key)
         {
             a[j+1]=a[j];
             j--;
         }
         a[j+1]=key;
          for(int k=1;k<=n;k++)
    k==n?cout<<a[k]<<endl:cout<<a[k]<<" ";
       }


    return 0;
}


#include <bits/stdc++.h>  
using namespace std;
 
int main()
{
    int i,j,n,temp;
    cin>>n;
    int a[n];
 
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=1;i<=n-1;i++)
    {
        temp=a[i];
        j=i-1;
 
        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];    //moves element forward
            j=j-1;
        }
 
        a[j+1]=temp;    //insert element in proper place
    }
 
    // for(i=0;i<n;i++)
    //     cout<<a[i]<<" ";
    // cout << endl;
 
    return 0;
}
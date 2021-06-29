#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,a[101]={0},num=0,minv=0,mint;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<n;i++)
    {
        minv=a[i+1];
        mint=i+1;
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]<minv)
            {
                mint=j;
                minv=a[j];
            }
        }
        if(a[i]>a[mint])
        {
            swap(a[i],a[mint]);
            num++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
        if(i<n) cout<<" ";
        else cout<<endl<<num<<endl;
    }
    return 0;
}

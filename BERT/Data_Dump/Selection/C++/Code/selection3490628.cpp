#include<bits/stdc++.h>
using namespace std;
int Selection(int *a,int n)
{
    int cnt=0;
    int minj;
    for(int i=0;i<n-1;++i)
    {
        minj=i;
        for(int j=i;j<n;++j)
        {
            if(a[j]<a[minj])
            {
                minj=j;
            }
        }
        swap(a[i],a[minj]);
        if(minj!=i)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin>>n;
    int a[105];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int cnt=Selection(a,n);
    for(int i=0;i<n;++i)
    {
        if(i>0)printf(" ");
printf("%d",a[i]);
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}

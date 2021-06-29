#include<bits/stdc++.h>
int x[100],c=0;
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&x[i]);
    for(int i=0; i<n-1; i++)
    {
        int minn=i;
        for(int j=i+1; j<n; j++)
        {
            if(x[j]<x[minn])
            {
                minn=j;
            }
        }
        if(minn!=i)
        {
            swap(x[i],x[minn]);
            c++;
        }
    }
    for(int k = 0; k < n; k++)
    {
        if(k != n-1)
        {
            printf("%d ",x[k]);
        }
        else
        {
            printf("%d\n",x[k]);
        }
    }
    cout<<c<<endl;
    return 0;
}



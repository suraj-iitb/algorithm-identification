#include <iostream>
#include <limits.h>

using namespace std;

int cnt=0;

void bubbleSort(int v[], int n)
{
    int i, j;
    for (i=1;i<=n;i++)
        for(j=1;j<=n-i;j++)
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
                cnt++;
            }
}

int main()
{
    int n,v[101];
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    bubbleSort(v,n);
    for(int i=1;i<=n;++i)
        if(i!=n)cout<<v[i]<<" ";
        else cout<<v[i]<<endl;
    cout<<cnt<<endl;
    return 0;
}


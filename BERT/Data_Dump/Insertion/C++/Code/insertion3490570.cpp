#include<bits/stdc++.h>
using namespace std;
void trace(int *a,int n)
{
    for(int i=0;i<n;++i)
    {
        cout<<a[i];
        if(i!=n-1)
        {
            cout<<" ";
        }
    }
    cout<<endl;
}
void Insertion(int *a,int n)
{
    int i,j,tmp;
    for(int i=0;i<n;++i)
    {
        tmp=a[i];
        j=i-1;
        while(j>=0&&a[j]>tmp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tmp;
        trace(a,n);
    }
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
    Insertion(a,n);
    return 0;
}

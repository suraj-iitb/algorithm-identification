#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[101];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<n;j++)
    {
        if(j!=0)
        {
            int key=a[j];
            int k=j-1;
            while(k>=0&&a[k]>key)
            {
                a[k+1]=a[k];
                k--;
            }
            a[k+1]=key;
        }
        for(int i=0;i<n-1;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<a[n-1]<<endl;
    }
    return 0;
}


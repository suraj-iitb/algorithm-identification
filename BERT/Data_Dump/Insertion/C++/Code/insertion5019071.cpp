#include <iostream>

using namespace std;

int main()
{
    int n,a[105];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int v;
    for(int i=0;i<n;i++)
    {
        if(i==0)
            cout<<a[i];
        else
            cout<<" "<<a[i];
    }
    cout<<endl;
    for(int i=1;i<n;i++)
    {
        v=a[i];
        int j=i-1;
        while(j>=0&&a[j]>v)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        for(int k=0;k<n;k++)
        {
            if(k==0)
                cout<<a[k];
            else
                cout<<" "<<a[k];
        }
        cout<<endl;
    }
    return 0;
}


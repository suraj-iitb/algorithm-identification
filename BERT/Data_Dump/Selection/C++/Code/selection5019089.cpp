#include <iostream>

using namespace std;

int main()
{
    int n,a[105],cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int minj;
    for(int i=0;i<n;i++)
    {
        minj=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[minj])
            {
                minj=j;
            }
        }
        if(minj!=i)
        {
            int t=a[minj];
            a[minj]=a[i];
            a[i]=t;
            cnt++;
        }

    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
            cout<<a[i];
        else
            cout<<" "<<a[i];
    }
    cout<<endl<<cnt<<endl;

    return 0;
}


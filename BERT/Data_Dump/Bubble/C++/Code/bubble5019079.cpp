#include <iostream>

using namespace std;

int main()
{
    int n,a[105],cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int i=0;
    int flag=1;
    while(flag)
    {
        flag=0;
        for(int j=n-1;j>=i+1;j--)
        {
            if(a[j]<a[j-1])
            {
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
                cnt++;
                flag=1;
            }
        }
        i++;
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


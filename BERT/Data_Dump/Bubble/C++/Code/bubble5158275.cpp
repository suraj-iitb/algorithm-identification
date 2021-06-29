#include <iostream>

using namespace std;

int main()
{
    int a[101];
    int t;
    cin>>t;
    int coun=0;
    for(int i=0;i<t;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<t;i++)
    {
        for(int j=t-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                coun++;
            }
        }
    }
        for(int i=0;i<t-1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[t-1]<<endl;
    cout<<coun<<endl;
    return 0;
}


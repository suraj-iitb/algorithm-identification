#include<iostream>
using namespace std;

int main()
{
    int i=0, n, a[100],j,temp=0, m=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(i=0;i<n;i++)
    {
        j=i-1;
        temp=a[i];
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        for(m=0;m<n;m++)
        {
            cout<<a[m];
            if(m!=(n-1))
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

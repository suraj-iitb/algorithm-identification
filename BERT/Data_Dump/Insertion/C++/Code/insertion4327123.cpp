#include <iostream>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            cout<<num[i]<<endl;
        }
        else cout<<num[i]<<' ';
    }
    for(int i=1;i<n;i++)
    {
        int j=i-1,temp=num[i],k=i-1;
        while(j>=0&&num[j]>=num[i])j--;
        while(k>j)
        {
            num[k+1]=num[k];
            k--;
        }
        num[j+1]=temp;
        for(k=0;k<n;k++)
        {
            if(k==n-1)cout<<num[k]<<endl;
            else cout<<num[k]<<' ';
        }
    }
    return 0;
}


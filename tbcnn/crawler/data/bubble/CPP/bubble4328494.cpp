#include <iostream>
using namespace std;
int main(void)
{
    int n,result=0;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    int i=0;
    while(i<n)
    {
        for(int j=n-1;j>i;j--)
        {
            if(num[j]<num[j-1])
            {
                swap(num[j],num[j-1]);
                result++;
            }
        }
        i++;
    }
    for(int i=0;i<n;i++)
    {
        if(i==n-1)cout<<num[i]<<endl;
        else cout<<num[i]<<' ';
    }
    cout<<result<<endl;
    return 0;
}


#include <iostream>
#include <cstdio>

using namespace std;

const int max_n=100;

int a[max_n];

int bubble_sort(int a[],int n)
{
    int cnt=0;
    bool flag=true;
    for(int i=0;i<n-1 && flag;++i)
    {
        flag=false;
        for(int j=1;j<n-i;++j)
        {
            if(a[j-1]>a[j])
            {
                a[j-1]^=a[j];
                a[j]^=a[j-1];
                a[j-1]^=a[j];
                cnt++;
                //cout<<">";
                flag=true;
            }
        }
    }
    return cnt;
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }

    int cnt=bubble_sort(a,n);

    for(int i=0;i<n-1;++i)
    {
        cout<<a[i]<<' ';
    }
    cout<<a[n-1]<<endl;

    cout<<cnt<<endl;
    return  0;
}


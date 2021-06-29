#include <iostream>
#include <cstdio>


using namespace std;

const int max_n=100;
int n;
int a[max_n];

int Select_sort(int a[],int n)
{
    int cnt=0;
    for(int i=0;i<n-1;++i)
    {
        int min_j=i;
        for(int j=i+1;j<n;++j)
        {
            if(a[j]<a[min_j])
            {
                min_j=j;
            }
        }
        if(min_j!=i)
        {
            a[min_j]^=a[i];
            a[i]^=a[min_j];
            a[min_j]^=a[i];
            cnt++;
        }
    }
    return cnt;
}


int main()
{
    //  输入数据
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }

    int cnt=Select_sort(a,n);

    for(int i=0;i<n-1;++i)
    {
        cout<<a[i]<<' ';
    }
    cout<<a[n-1]<<endl;
    cout<<cnt<<endl;

    return 0;
}


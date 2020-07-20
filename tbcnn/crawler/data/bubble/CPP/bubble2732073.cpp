#include<iostream>

using namespace std;

int bubble_sort(int a[],int n)
{
    int cnt=0;
    bool flag=true;
    for(int i=0;i<n-1&&flag;i++)
    {
        flag=false;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                cnt++;
                flag=true;
            }
        }
    }
    return cnt;
}

int main()
{
    int n;
    int a[101];

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int cnt=bubble_sort(a,n);

    for(int i=0;i<n;i++)
    {
        if(i)
        {
            cout<<" ";
        }
        cout<<a[i];
    }

    cout<<endl<<cnt<<endl;

    return 0;
}


#include<iostream>

using namespace std;

int selection_sort(int a[],int n)
{
    int cnt=0;

    for(int i=0;i<n-1;i++)
    {
        int Min=i;
        int j;
        for(j=i+1;j<n;j++)
        {
            if(a[Min]>a[j])
            {
                Min=j;
            }
        }
        if(i!=Min)
        {
            swap(a[Min],a[i]);
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    int n,a[101];

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int cnt=selection_sort(a,n);

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


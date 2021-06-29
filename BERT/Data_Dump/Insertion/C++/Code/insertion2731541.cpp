#include<iostream>

using namespace std;

void Show(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(i)
        {
            cout<<" ";
        }
        cout<<a[i];
    }
    cout<<endl;
}

void Insertion_sort(int a[],int n)
{
    Show(a,n);
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        Show(a,n);
    }
}

int main()
{
    int a[101];
    int n;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    Insertion_sort(a,n);

    return 0;
}


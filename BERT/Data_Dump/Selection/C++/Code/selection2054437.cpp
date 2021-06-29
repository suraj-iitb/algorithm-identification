#include<iostream>
using namespace std;
#define maxn 105
int a[maxn];
int n;
int k=0;
void selectionSort()
{
    for(int i=0;i<n;i++)
    {
        int minindex=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[minindex])
                minindex=j;
        }
        if(i!=minindex)
        {


        swap(a[i],a[minindex]);
        k++;

        }
    }
         for(int i=0;i<n;i++)
    {
        if(i!=n-1)
            cout<<a[i]<<" ";
        else
            cout<<a[i]<<endl;
    }
    cout<<k<<endl;
}
int main()
{
    while(cin>>n)
    {

        for(int i=0;i<n;i++)
            cin>>a[i];
        selectionSort();
    }
    return 0;
}

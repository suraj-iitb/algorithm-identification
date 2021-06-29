#include<iostream>
using namespace std;
int bubblesort(int a[],int n)
{
    int flag=1,times=0,i=0;
    while(flag)
    {
        flag=0;
        for(int j=n-1;j>=i+1;j--)
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
                times++;
                flag=1;
            }
        i++;
    }
    return times;
}
int main()
{
    int a[100],times;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    times=bubblesort(a,n);
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<' ';
    cout<<a[n-1];
    cout<<endl;
    cout<<times<<endl;
    return 0;
}

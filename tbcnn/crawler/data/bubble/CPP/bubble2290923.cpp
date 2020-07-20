#include<iostream>
using namespace std;
int  main()
{
    int N;
    int m=0;
    cin>>N;
    int a[100];
    for(int i=0;i<N;i++)
        cin>>a[i];
    for(int i=0;i<N-1;i++)
        for(int j=0;j<N-1-i;j++)
    {
    int t;
    if(a[j]>a[j+1])
    {

        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
        m++;
    }
    }
    for(int i=0;i<N;i++)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<m<<endl;
    return 0;
}

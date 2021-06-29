#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int a[N+1];
    for(int i=1;i<=N;i++)cin>>a[i];
    int times=0;
    for(int i=1;i<N;i++)
    {
        for(int j=N;j>i;j--)
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                times++;
            }
    }
    for(int i=1;i<N;i++)cout<<a[i]<<' ';
    cout<<a[N]<<endl;
    cout<<times<<endl;
    return 0;
}

#include <iostream>
using namespace std;

int main(void)
{
    int i, n;
    cin>>n;
    int a[n];
    int c[10001];
    for(i=0; i<10001; i++)
        c[i] = 0;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        c[a[i]]++;
    }
    for(i=1; i<10001; i++)
        c[i] += c[i-1];
    int b[n+1];
    for(i=n; i>=1; i--)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    for(i=1; i<=n; i++)
    {
        if(i!=n)
            cout<<b[i]<<' ';
        else
            cout<<b[i]<<endl;
    }
}

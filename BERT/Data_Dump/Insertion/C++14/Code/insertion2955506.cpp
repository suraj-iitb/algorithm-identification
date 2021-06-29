#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[100];
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++)
    {
        for (int j=i; a[j-1]>a[j] && j>0; j--)
        {
            swap(a[j-1], a[j]);
        }
        for (int j=0; j<n; j++)
        {
            if (j!=n-1) cout<<a[j]<<' ';
            else cout<<a[j]<<'\n';
        }
    }
    return 0;
}


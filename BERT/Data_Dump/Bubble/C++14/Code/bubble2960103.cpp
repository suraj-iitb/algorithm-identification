#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[100], cnt=0;
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1; j++)
        {
            if (a[j]>a[j+1])
            {
                swap(a[j], a[j+1]);
                cnt++;
            }
        }
    }
    for (int i=0; i<n; i++)
    {
        if (i!=n-1) cout<<a[i]<<' ';
        else cout<<a[i]<<'\n';
    }
    cout<<cnt<<'\n';
    return 0;
}


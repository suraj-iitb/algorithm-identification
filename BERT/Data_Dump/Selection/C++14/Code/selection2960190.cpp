#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[100], _min, cnt=0;
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++)
    {
        _min=i;
        for (int j=i; j<n; j++)
        {
            if (a[j]<a[_min]) _min=j;
        }
        if (_min!=i)
        {
            swap(a[i], a[_min]);
            cnt++;
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


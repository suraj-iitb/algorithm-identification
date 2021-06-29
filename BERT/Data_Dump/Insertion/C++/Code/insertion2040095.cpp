#include <iostream>
#include <vector>
using namespace std;
void show(const vector<int> &a,int n)
{
    int i;
    for(i=0;i<n-1;i++)
        cout<<a[i]<<' ';
    cout<<a[i]<<endl;
    return;
}
int main ()
{
    vector<int> a;
    int n,m,j,i,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        a.push_back(m);
    }
    show(a,n);
    for(i=1;i<n;i++)
    {
        m = a[i];
        j = i-1;
        while(j>=0&&a[j]>m)
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = m;
        show(a,n);
    }
    return 0;
}

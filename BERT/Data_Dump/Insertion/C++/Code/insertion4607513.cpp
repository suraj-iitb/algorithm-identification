#include <iostream>
#include <algorithm>

using namespace std;

void trace(int x[], const int N)
{
    int k;
    for(k=0; k<N-1; k++)
    {
        cout<<x[k]<<" ";
    }
    cout<<x[k]<<endl;
}
static const int LEN=100;

void insertsort(int x[],const int N)
{
    for(int i=1; i<N; i++)
    {
        int j=i-1;
        int v=x[i];
        while(j>=0&&x[j]>v)
        {
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=v;
        trace(x,N);
    }
}
int main()
{
    int x[LEN];
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>x[i];
    trace(x,n);
    insertsort(x,n);
    return 0;
}


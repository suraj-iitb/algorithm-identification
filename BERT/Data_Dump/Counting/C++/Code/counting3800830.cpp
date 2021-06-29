#include<iostream>
#define int long long
using namespace std;
int A[2000005];
int B[2000005];
int C[10005];
int n,k=10001;
int CountSort()
{
    for(int i=0;i<k;i++)
        C[i]=0;
    for(int i=1;i<=n;i++)cin>>A[i],C[A[i]]++;
    for(int i=1;i<=k;i++)C[i]+=C[i-1];
    for(int i=n;i>0;i--)B[C[A[i]]]=A[i],C[A[i]]--;
    cout<<B[1];
    for(int i=2;i<=n;i++)cout<<' '<<B[i];
    cout<<endl;
}
signed main()
{
    cin>>n;
    CountSort();
    return 0;
}


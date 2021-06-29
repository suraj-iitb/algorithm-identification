#include<iostream>
#include<cstring>
using namespace std;

#define MAX_INT 10100
int A[2000100];
int C[MAX_INT];
int B[2000100];

int main()
{
    int n;cin >>n;
    memset(A,sizeof(A),0);
    memset(B,sizeof(B),0);
    for(int i=1;i<=n;++i)
    {
        cin >> A[i];
    }
    memset(C,sizeof(C),0);
    for(int i =1;i<=n;++i)
    {
        C[A[i]]++;
    }
    for(int j=1;j<MAX_INT;++j)
    {
        C[j] = C[j] + C[j-1];
    }

    for(int k =1;k<=n;++k)
    {
        B[C[A[k]]] = A[k];
        C[A[k]]--;
    }
    for(int i=1;i<=n;++i)
    {
        if(i==1)cout << B[i];
        else
        {
            cout << " " << B[i];
        }
    }
    cout<<endl;
    return 0;
}

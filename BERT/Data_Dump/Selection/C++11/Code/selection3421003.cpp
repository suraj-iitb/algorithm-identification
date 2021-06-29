#include <bits/stdc++.h>
using namespace std;
int cnt=0;
void selectionSort(int A[],int N)
{
    for(auto i=0;i<N;i++)
    {
        int minj=i;
        for(int j=i;j<N;j++){
            if(A[j]<A[minj])
                minj=j;
        }
        if(i!=minj){
            int t=A[i];
            A[i]=A[minj];
            A[minj]=t;
            cnt++;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];
    selectionSort(a,n);
    for(int i=0;i<n;i++)
    {
        if(i>0)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl<<cnt<<endl;
    return 0;
}


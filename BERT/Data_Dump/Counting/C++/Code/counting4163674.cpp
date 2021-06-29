#include <iostream>
//#define k 10001
using namespace std;

void CountingSort(int A[],int n,int B[],int k){
    int C[k];
    for(int i=0;i<k;i++)
        C[i]=0;
    for(int i=0;i<n;i++)
        C[A[i]]++;
    for(int i=1;i<k;i++)
        C[i]=C[i]+C[i-1];
    for(int i=n-1;i>=0;i--)
    {
        if(C[A[i]]>0){
            B[C[A[i]]-1]=A[i];
            C[A[i]]--;
        }
    }
}

int main(){
    int *A,*B;
    int k=10001;
    int n;
    cin>>n;
    A=new int[n];
    B=new int[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    CountingSort(A,n,B,k);
    int isn=0;
    for(int i=0;i<n;i++)
    {
        if(isn++>0)cout<<' ';
        cout<<B[i];
    }
    cout<<endl;
    delete A;
    delete B;
    return 0;
}

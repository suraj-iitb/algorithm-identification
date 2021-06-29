#include <iostream>

using namespace std;
#define MAX 2000001
#define VMAX 10000
int A[MAX];
int B[MAX];
void countsort(int A[],int B[],int n){
    int C[VMAX+1];
    for(int i=0;i<=VMAX;i++){
        C[i] = 0;
    }
    for(int j=0;j<n;j++){
        C[A[j]]++;
    }
    for(int i=1;i<VMAX;i++){
        C[i] = C[i]+C[i-1];
    }
    for(int j=n-1;j>=0;j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int k = A[0];
    for(int i=1;i<n;i++){
        if(A[i]>k)
            k = A[i];
    }
    countsort(A,B,n);
    for(int i=1;i<n+1;i++){
        if(i>1) cout<<" ";
        cout<<B[i];
    }
    cout<<endl;
    return 0;
}


#include <iostream>
using namespace std;
int SelectSort(int A[],int N){
    int i,j,t,sw=0,minj;
    for ( i = 0; i < N-1; ++i) {
       minj=i;
        for ( j = i; j < N; ++j)
            if(A[j]<A[minj]) minj=j;
        t=A[i],A[i]=A[minj],A[minj]=t;
        if(i!=minj) sw++;
    }
    return sw;
}
int main() {
    int n,i,a[110],sw;
    cin>>n;
    for (i = 0; i < n; ++i) cin>>a[i];
    sw=SelectSort(a,n);
    for ( i = 0; i < n; ++i) {
        if(i) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<sw<<endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
void trace(int A[],int N){
    for(int i=0;i<N;i++){
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}
void insertionSort(int A[],int N){
    for(int i=1;i<N;i++){
        int v=A[i];
        int j=i-1;
        while(j>=0 && v<A[j]){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        trace(A,N);
    }
}
int main() {
    int n;cin>>n;
    int A[n];
    rep(i,n) cin>>A[i];
    trace(A,n);
    insertionSort(A,n);
}

#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
typedef long long ll;
using namespace std;

//配列の要素を順番に出力
void trace(int A[], int N){
    rep(i,N){
        if (i!=0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

void insertion(int A[],int N){
    for (int i=1; i<N; i++){
        int v=A[i];
        int j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        trace(A,N);
    }
}

int main(){
    int N;
    int A[100];
    scanf("%d",&N);
    rep(i,N) scanf("%d",&A[i]);
    trace(A,N);
    insertion(A,N);
    return 0;
}

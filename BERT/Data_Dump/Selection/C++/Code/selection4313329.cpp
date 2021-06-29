#include <bits/stdc++.h>
using namespace std;
#define rep(i,i0,n) for(int i=i0;i<n;++i)
#define ll long long

int N,ans;
int A[100];

void show(){
    rep(i,0,N){
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void selectionSort(){
    rep(i,0,N){
        int minj = i;
        rep(j,i,N){
            if(A[j] < A[minj]) minj = j;
        }
        if(i != minj) {
            swap(A[i], A[minj]);
            ans++;
        }
    }
}

int main() {
    scanf("%d", &N);
    rep(i,0,N) scanf("%d", &A[i]);
    ans=0;
    selectionSort();
    show();
    printf("%d\n",ans);
}

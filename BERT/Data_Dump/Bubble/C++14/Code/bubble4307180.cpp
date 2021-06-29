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

void bubbleSort(){
    bool flag = true;
    ans = 0;
    while(flag){
        flag = false;
        for(int j=N-1;j>=1;--j){
            if(A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                ans++;
                flag = true;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    rep(i,0,N) scanf("%d", &A[i]);
    bubbleSort();
    show();
    printf("%d\n",ans);
}

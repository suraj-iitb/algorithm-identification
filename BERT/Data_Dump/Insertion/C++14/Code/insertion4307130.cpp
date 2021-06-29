#include <bits/stdc++.h>
using namespace std;
#define rep(i,i0,n) for(int i=i0;i<n;++i)
#define ll long long

int main() {
    // input
    int n;
    scanf("%d", &n);
    int a[n];
    rep(i,0,n) scanf("%d", &a[i]);
    rep(k,0,n) {
        if(k != 0) printf(" ");
        printf("%d", a[k]);
    }
    printf("\n");
    //sort
    rep(i,1,n){
        int v = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        rep(k,0,n) {
            if(k != 0) printf(" ");
            printf("%d", a[k]);
        }
        printf("\n");
    }   
}

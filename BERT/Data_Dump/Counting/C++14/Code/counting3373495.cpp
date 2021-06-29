#include <iostream>
#include <string>
#include <cstdio>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define rep1(i,n) for(int i=1 ; i <= n ; i++)

using namespace std;

int n;
void CountingSort(int x[],int b[] ,int max){
    int c[max+10];

    rep(i,max+2) c[i] = 0;

    rep1(i,n){
        c[x[i]]++;
    }

    rep1(i,max){
        c[i] = c[i] + c[i-1];
    }

    for(int i=n ; i > 0 ; i--){
        b[c[x[i]]] = x[i];
        c[x[i]]--;
    }

}

int main(){
    cin >> n;
    int a[n+10],b[n+10];
    int maxn = 0;
    rep1(i,n) {
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }

    CountingSort(a,b,maxn);

    rep1(i,n){
        cout << b[i] << (i != n ? ' ' : '\n');
    }
}

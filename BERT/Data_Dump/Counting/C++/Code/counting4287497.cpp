#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)

int n;
void counting_sort(int a[], int b[], int k){
    int c[k+1] = {0};
    rep(i,n)c[a[i]]++;
    REP(i,1,k+1)c[i] += c[i-1];
    
    for(int i = n-1;i>=0;i--){
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
}

int main(){
    cin >> n;
    int a[n], b[n + 1], m = -1;
    rep(i,n){
        cin >> a[i];
        m = max(m, a[i]);
    }
    //cout << m << endl;
    counting_sort(a, b, m);

    rep(i,n){
        cout << b[i];
        if(i < n-1)printf(" ");
        else printf("\n");
    }
    return 0;
}

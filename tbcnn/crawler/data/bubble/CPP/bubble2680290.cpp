#include <bits/stdc++.h>

#define pout(n)  printf ("%d\n", n)

#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());

const int d4x[4] = {1, 0, -1, 0};
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const int d8y[8] = { 0,1,1,1,0,-1,-1,-1 };

#define MAX_N (int)2e5+20
#define INF 1e12+20

typedef long long ll;
using namespace std;

int n,c = 0;;
int main() {
    cin >> n;
    int a[n];
    rep(i,0,n){
        cin >> a[i];
    }
    rep(i,0,n){
        per(j,n,i+1){
            if(a[j] < a[j-1]){
                swap(a[j],a[j-1]);
                c++;    
            }
        }
    }

    rep(i,0,n){
        printf("%d",a[i]);
        if(i != n-1) printf(" ");
    }
    printf("\n");
    pout(c);
    return 0;
}

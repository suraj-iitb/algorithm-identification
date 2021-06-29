#include <iostream>
#include <cstdio>
using namespace std;

#define rep(i,n,m) for(int i=n; i<=m; i++)
#define per(i,n,m) for(int i=n; i>=m; i--)
#define print(x) printf("%d ", x);
#define println(x) printf("%d\n", x);
#define printarray(a,n) for(int i=0; i<n-1; i++){printf("%d ", a[i]);} printf("%d\n", a[n-1]);
#define scan(x) scanf("%d", &x);
#define scanarray(a,n) for(int i=0; i<n; i++){scanf("%d", &a[i]);}

void selectionsort(int *a, int n);

int main() {
    int n;
    scan(n);
    int a[n];
    scanarray(a,n);

    selectionsort(a,n);

    return 0;
}

void selectionsort(int *a, int n) {
    int minj = 0;
    int swapcount = 0;
    rep(i,0,n-1) {
        minj = i;
        rep(j,i,n-1) {
            if(a[j] < a[minj]) {
                minj = j;
            }
        }
        if(i != minj) {
            swap(a[i],a[minj]);
            swapcount++;
        }
    }
    printarray(a,n);
    println(swapcount);

}


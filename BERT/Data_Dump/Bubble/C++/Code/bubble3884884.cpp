#include <iostream>
#include <cstdio>
using namespace std;

#define rep(i,n,m) for(int i=n; i<=m; i++)
#define per(i,n,m) for(int i=n; i>=m; i--)
#define print(x) printf("%d ", x);
#define println(x) printf("%d\n", x);
#define printarray(a,n) for(int i=0; i<n-1; i++){printf("%d ", a[i]);} printf("%d\n", a[n-1]);

void bubblesort(int *a, int n);

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i,0,n-1) cin >> a[i];

    bubblesort(a,n);

    return 0;
}

void bubblesort(int *a, int n) {
    int swapcount = 0;
    int flag = 1;
    while(flag == 1) {
        flag = 0;
        per(i,n-1,1) {
            if(a[i] < a[i-1]) {
                swap(a[i],a[i-1]);
                flag = 1;
                swapcount++;
            }
        }
    }

    printarray(a,n);
    cout << swapcount << endl;

}


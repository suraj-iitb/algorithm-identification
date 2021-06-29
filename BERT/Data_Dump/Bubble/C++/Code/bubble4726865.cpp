#include <bits/stdc++.h>
using namespace std;

void trace(int a[], int n) {
    for (int i=0; i<n; i++) {
        if ( i > 0 ) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int bubbleSort(int a[], int n) { //N個の配列の要素を含む0-オリジンの配列a
    int sortNum = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j=n-1; j>0; j--) {
            if (a[j] < a[j-1]) {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                sortNum++;
                flag = true;
            }
        }
    }
    return sortNum;
}

int main() {
    int n;
    int a[110];
    int ans;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    ans = bubbleSort(a, n);
    trace(a, n);
    cout << ans << endl;
    return 0;
}

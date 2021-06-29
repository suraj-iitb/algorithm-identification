#include <bits/stdc++.h>
using namespace std;

void trace(int a[], int n) {
    for (int i=0; i<n; i++) {
        if ( i > 0 ) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int selectionSort(int a[], int n) { //N個の配列の要素を含む0-オリジンの配列a
    int sortNum = 0;
    for (int i=0; i<n; i++) {
        int minj = i;
        for (int j=i; j<n; j++) {
            if (a[j] < a[minj]) minj = j;
        }
        if (minj != i) {
            int temp = a[minj];
            a[minj] = a[i];
            a[i] = temp;
            sortNum++;
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
    ans = selectionSort(a, n);
    trace(a, n);
    cout << ans << endl;
    return 0;
}

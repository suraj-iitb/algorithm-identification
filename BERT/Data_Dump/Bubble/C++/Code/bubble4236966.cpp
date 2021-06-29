#include <bits/stdc++.h>
using namespace std;
int bubbleSort(int a[], int n) {
    bool flag = true;
    int s = 0;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j - 1] > a[j]) {
                s++;
                flag = true;
                int t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
            }
        }
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];
    int s = bubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << s << endl;
    return 0;
}

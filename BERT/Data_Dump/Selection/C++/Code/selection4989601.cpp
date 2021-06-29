#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    int a[x];
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }

    int cn;
    for (int i = 0; i < x - 1; i++) {
        int minIndex = i;
        for (int j = i; j < x; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
        if (minIndex != i) {
            cn++;
        }
    }
    for (int i = 0; i < x - 1; i++) {
        cout << a[i] << ' ';
    }
    cout << a[x - 1] << endl
         << cn << endl;
}

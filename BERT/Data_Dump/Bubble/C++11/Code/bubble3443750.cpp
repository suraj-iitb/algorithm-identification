#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void trace(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}


int main() {
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int flag = 0;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (flag) {
            break;
        }
        flag = 1;
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j-1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                flag = 0;
                cnt++;
            }
        }
    }

    trace(a, n);
    cout << cnt << endl;

    return 0;
}


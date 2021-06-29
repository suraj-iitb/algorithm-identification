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

int selectionSort(int *a, int n) {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_offset = i;
        for (int j = i + 1; j < n; j++) {
            if (a[min_offset] > a[j]) {
                min_offset = j;
            }
        }
        if (i != min_offset) {
            int tmp = a[i];
            a[i] = a[min_offset];
            a[min_offset] = tmp;
            cnt++;
        }
    }
    return cnt;
}


int main() {
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = selectionSort(a, n);

    trace(a, n);
    cout << cnt << endl;
    return 0;
}


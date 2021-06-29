#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int selectionSort(int *arr, int n) {
    int cnt = 0;
    int min, min_i;
    for (int i = 0; i < n - 1; i++) {
        /* find minimu value */
        for (int j = i; j < n; j++) {
                if (j == i)
                    min = arr[j];
                else {
                    if (min > arr[j]) {
                        min = arr[j];
                        min_i = j;
                    }
                }
            }

        if (arr[i] > min) {
            swap(arr[i], arr[min_i]);
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int n, cnt;
    int *val;

    cin >> n;
    val = new int(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cnt = selectionSort(val, n);
    for (int i = 0; i < n; i++) {
        cout << val[i];
        if (i != n - 1)
            cout << " ";
    }
            
    cout << endl << cnt << endl;

    return 0;
}

#include "bits/stdc++.h"

using namespace std;

int SelectionSort(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) minj = j;
        }
        if (minj != i) {
            int tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
            count++;
        }
    }

    return count;
} 

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 

    int count = SelectionSort(a, n);

    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << a[i];
    }

    cout << endl << count << endl;

    return 0;
}

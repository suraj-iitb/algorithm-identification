#include <iostream>

using namespace std;

void printCurrent(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

int selectionSort(int a[], int n) {
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (a[minj] > a[j]) {
                minj = j;
            }
        }
        if (minj != i) {
            int tmp = a[minj];
            a[minj] = a[i];
            a[i] = tmp;
            c++;
        }
    }
    printCurrent(a, n);
    return c;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int c = selectionSort(a, n);
    cout << c << endl;

    return 0;
}

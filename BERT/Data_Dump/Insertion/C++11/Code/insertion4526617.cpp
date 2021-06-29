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

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i;
        while (v < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
        printCurrent(a, n);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    printCurrent(a, n);
    insertionSort(a, n);

    return 0;
}

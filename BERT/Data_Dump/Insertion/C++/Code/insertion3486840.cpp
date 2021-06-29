#include <iostream>

using namespace std;

int n, a[100];

void printArray() {
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 1; i < n; ++i) {
        printArray();
        int v = a[i], j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
    printArray();

    return 0;
}

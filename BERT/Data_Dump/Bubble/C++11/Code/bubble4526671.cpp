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

int bubbleSort(int a[], int n) {
    int c = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (a[j] < a[j - 1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                c++;
            }
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
    int c = bubbleSort(a, n);
    cout << c << endl;

    return 0;
}

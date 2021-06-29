#include <iostream>
using namespace std;

int selectionSort(int a[], int n) {
    int swapNum = 0;
    int minj;
    for (int i = 0; i < n - 1; i++) {
        minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        swap(a[i], a[minj]);
        if (i != minj) {
            swapNum++;
        }
    }
    return swapNum;
}

int main() {
    int a[100], n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int swapNum = selectionSort(a, n);

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    cout << swapNum << endl;
}


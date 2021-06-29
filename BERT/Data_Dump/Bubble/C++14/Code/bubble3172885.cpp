#include <iostream>
using namespace std;

int bubbleSort(int a[], int n) {
    int swapNum = 0;
    bool isSwaped = true;
    for (int i = 0; isSwaped; i++) {
        isSwaped = false;
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                isSwaped = true;
                swapNum++;
            }
        }
    }
    return swapNum;
}

int main() {
    int a[100], n, swapNum;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    swapNum = bubbleSort(a, n);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << swapNum << endl;
}


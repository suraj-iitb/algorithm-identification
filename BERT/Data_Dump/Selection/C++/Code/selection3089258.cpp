#include <iostream>
using namespace std;

int selectionSort(int *a, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        int minj = i;
        for (int j = i; j < size; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (a[i] > a[minj]) {
            swap(a[i], a[minj]);
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];

    int c = selectionSort(a, n);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << c << endl;
    return 0;
}

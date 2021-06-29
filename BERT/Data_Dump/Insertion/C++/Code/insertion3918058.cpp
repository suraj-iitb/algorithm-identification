#include <iostream>

using namespace std;

void outputArray(int *arr, int n);

int main() {
    int n, t;
    int array[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> array[i];
    outputArray(array, n);
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int v = array[i];
        while (j >= 0 && v < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = v;
        outputArray(array, n);
    }
    return 0;
}

void outputArray(int *arr, int n) {
    for (int i = 0; i < n; i++)
        if (i == n - 1) {
            cout << arr[i] << endl;
        } else {
            cout << arr[i] << " ";
        }
}

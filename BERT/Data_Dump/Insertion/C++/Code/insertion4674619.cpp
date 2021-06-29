#include <iostream>

using namespace std;

void insertSort(int* a, int n) {
    // ソートする前
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[n - 1] << "\n";

    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;

        while ( (j >= 0) && (a[j] > v) ) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;

        for (int i = 0; i < n - 1; i++)
            cout << a[i] << " ";
        cout << a[n - 1] << "\n";
    }
}

int main() {
    int N;

    cin >> N;
    int* a = new int[N];

    for (int i = 0; i < N; i++)
        cin >> a[i];

    insertSort(a, N);

    return (0);
}

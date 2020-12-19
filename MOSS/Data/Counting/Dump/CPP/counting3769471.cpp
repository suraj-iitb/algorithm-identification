#include <iostream>

using namespace std;

int n;
int a[2000000], b[2000000], c[10001];

void countingSort(int a[], int b[]) {
    for (int i = 0; i < n; ++i)
        c[a[i]]++;
    for (int i = 1; i <= 10000; ++i)
        c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    countingSort(a, b);
    for (int i = 0; i < n; ++i) {
        cout << b[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}

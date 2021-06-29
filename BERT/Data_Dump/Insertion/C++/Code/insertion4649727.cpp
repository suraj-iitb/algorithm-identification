#include <iostream>
using namespace std;
static const int MAX_N = 100;

void show(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << a[i];
        }
        else {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int a[MAX_N] = {0};
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++)  cin >> a[i];
    show(a, N);
    for (int i = 1; i < N; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        show(a, N);
    }

    return 0;
}

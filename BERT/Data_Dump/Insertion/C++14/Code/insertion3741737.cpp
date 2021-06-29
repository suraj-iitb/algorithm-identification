#include <iostream>
using namespace std;
int a[100];
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << ' ';
    cout << a[n - 1] << '\n';

    for (int k = 1; k < n; k++) {
        int j = k;
        while (a[j] < a[j - 1]) {
            swap(a[j], a[j - 1]);
            j--;
        }
        for (int i = 0; i < n - 1; i++) {
            cout << a[i] << ' ';
        } cout << a[n - 1] << '\n';
    }
    return 0;
}

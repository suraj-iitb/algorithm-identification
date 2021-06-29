#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i == n - 1) cout << endl;
        else cout << ' ';
    }
    for (int i = 1; i < n; i++) {
        int tmp = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] < tmp) break;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
        for (int k = 0; k < n; k++) {
            cout << arr[k];
            if (k == n - 1) {}
            else cout << ' ';
        }
        cout << endl;
    }
}

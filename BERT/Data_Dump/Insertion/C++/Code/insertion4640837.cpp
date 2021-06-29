#include <iostream>
using namespace std;
static const int N_MAX = 100;

int main() {
    int n, arr[N_MAX];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            cout << arr[j] << " ";
        }
        cout << arr[n - 1] << endl;

        int v = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > v) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;
    }

    for (int j = 0; j < n-1; j++) {
        cout << arr[j] << " ";
    }
    cout << arr[n - 1] << endl;

    return 0;
}

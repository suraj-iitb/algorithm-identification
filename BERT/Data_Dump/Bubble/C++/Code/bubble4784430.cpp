#include <iostream>
#include <vector>
using namespace std;

void trace(vector<int> a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

int bubbleSort(vector<int> a, int n) {
    int cnt = 0;
    bool f = true;
    for (int i = 0; f; i++) {
        f = false;
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                f = true;
                cnt++;
            }
        }
    }
    trace(a, n);
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = bubbleSort(a, n);
    cout << cnt << endl;
}


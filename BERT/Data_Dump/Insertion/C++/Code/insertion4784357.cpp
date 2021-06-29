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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    trace(a, n);

    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        trace(a, n);
    }

}


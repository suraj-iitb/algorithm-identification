#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

void trace(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

void bubbleSort(vector<int>& a) {
    int n = a.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                swapped = true;
                count++;
            }
        }
        if (!swapped) {
            break;
        }
    }
    trace(a);
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bubbleSort(a);
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int minIdx = i;
        for (int j = i; j < n; j++) {
            if (a[minIdx] > a[j]) minIdx = j;
        }
        if (minIdx != i) {
            swap(a[i], a[minIdx]);
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl << count << endl;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    selectionSort(a, n);

    return 0;
}

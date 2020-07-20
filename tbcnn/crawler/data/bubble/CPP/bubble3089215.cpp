#include <iostream>

using namespace std;

int bubbleSort(int *a, int size) {
    bool flag = true;
    int count = 0;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = size - 1; j >= i + 1; j--) {
            if (a[j - 1] > a[j]) {
                count++;
                flag = true;
                swap(a[j], a[j - 1]);
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];
    int c;
    c = bubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << c << endl;
    return 0;
}

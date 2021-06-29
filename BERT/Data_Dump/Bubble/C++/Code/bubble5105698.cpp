#include<iostream>
using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

void bubbleSort(int a[], int n) {
    int cnt = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = n - 1; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = true;
                cnt++;
            }
        }
    }
    print(a, n);
    cout << cnt << endl;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    bubbleSort(a, n);
    return 0;
}

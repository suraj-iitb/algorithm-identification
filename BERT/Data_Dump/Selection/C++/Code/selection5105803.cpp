#include<iostream>
using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

void selectionSort(int a[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(a[i], a[minj]);
            cnt += 1;
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
    selectionSort(a, n);
}

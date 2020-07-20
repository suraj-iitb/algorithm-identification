#include <iostream>
using namespace std;

static const int N_MAX = 100;

int bubbleSort(int a[], int n) {
    int flag = 1, cnt = 0;
    while (flag) {
        flag = 0;

        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] < a[i-1]) {
                swap(a[i], a[i - 1]);
                flag = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

void trace(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}

int main() {
    int n, a[N_MAX];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = bubbleSort(a, n);
    trace(a, n);
    cout << cnt << endl;
}

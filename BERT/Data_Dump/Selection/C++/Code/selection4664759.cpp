#include <iostream>
using namespace std;

static const int N_MAX = 100;

int selectionSort(int a[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(a[i], a[minj]);
            cnt++;
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

    int cnt = selectionSort(a, n);
    trace(a, n);
    cout << cnt << endl;
}

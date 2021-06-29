#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

void bubbleSort(int *array, int N) {
    int cnt = 0;
    while (true) {
        bool is_sorted = true;
        for (size_t i = N - 1; i >= 1; i--) {
            if (array[i] < array[i - 1]) {
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                is_sorted = false;
                cnt++;
            }
        }
        if (is_sorted)
            break;
    }

    for (int i = 0; i < N; i++) {
        cout << array[i] << ((i != N - 1) ? " " : "\n");
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int *array = new int[n];
    rep(i, n) cin >> array[i];
    bubbleSort(array, n);
}


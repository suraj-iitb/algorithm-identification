#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

void SelectionSort(int *array, int N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (array[j] < array[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            int temp = array[i];
            array[i] = array[minj];
            array[minj] = temp;
            cnt++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << array[i];
        cout << ((i != N - 1) ? " " : "\n");
    }
    cout << cnt << endl;
}

int main() {
    int n;
    cin >> n;

    int *array = new int[n];
    rep(i, n) cin >> array[i];

    SelectionSort(array, n);
    delete array;
}



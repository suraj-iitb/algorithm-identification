#include <bits/stdc++.h>
using namespace std;

int selectionSort(int a[], int n) {
    int total_swap = 0;

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[min] > a[j]) min = j;
        }

        if (i != min) {
            swap(a[i], a[min]);
            total_swap++;
        }
    }

    return total_swap;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int count = selectionSort(a, n);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }

    cout << endl << count << endl;

    return 0;
}


#include <iostream>

using namespace std;

const int MAX = 100;

int selection_sort(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n-1; ++i) {
        int min_j = i;
        for (int j = i+1; j < n; ++j) {
            if (a[j] < a[min_j]) min_j = j;
        }
        if (min_j != i) {
            int t = a[i]; a[i] = a[min_j]; a[min_j] = t;
            ++count;
        }
    }
    return count;
}

int main() {
    int N;
    int a[MAX];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    int count = selection_sort(a, N);
    for (int i = 0; i < N; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl << count << endl;

    return 0;
}

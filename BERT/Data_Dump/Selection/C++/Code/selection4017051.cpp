#include <iostream>
#include <algorithm>
using namespace std;
int selectionSort(int a[], int n);

int main() {

    int a[100], n, count;
    count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    count = selectionSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << (i < n - 1 ? " " : "\n");
    cout << count << endl;

    return 0;
}

int selectionSort(int a[], int n) {
    int count, i, j, minj;
    count = 0;
    for (i = 0; i < n; i++) {
        minj = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[minj]) minj = j;
        }
        if (minj != i) {
            swap(a[i], a[minj]);
            count++;
        }
    }
    return count;
}

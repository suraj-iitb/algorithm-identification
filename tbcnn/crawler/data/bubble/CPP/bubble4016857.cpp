#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100

void swap(int *a, int *b);
int bubbleSort(int a[], int n);
int main() {
    int n, a[MAX];
    cin >> n;
    int i, j, count;
    for (i = 0; i < n; i++) cin >> a[i];
    count = bubbleSort(a, n);

    for (i = 0; i < n; i++) cout << a[i] << (i < n - 1 ? " " : "\n");
    cout << count << endl;

    return 0;
}

int bubbleSort(int a[], int n) {
    int count, i, j;
    count = 0;
    bool flag = 1;
    for (i = 0; flag; i++) {
        flag = 0;
        for (j = n - 1; j >= i + 1; j--) {
            if (a[j - 1] > a[j]) {
                flag = 1;
                swap(a[j - 1], a[j]);
                count++;
            }
        }
    }
    return count;
}

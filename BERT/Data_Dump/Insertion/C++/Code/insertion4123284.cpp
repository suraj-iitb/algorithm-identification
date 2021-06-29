#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++)
        cout << a[i] << ' ';
    cout << a[n - 1] << endl;
    void InsertionSort(int, int[]);
    InsertionSort(n, a);
    return 0;
}

void InsertionSort(int n, int a[]) {
    for(int i = 1, j; i < n; i++) {
        int temp = a[i];
        for(j = i - 1; j >= 0 && a[j] > temp; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;
        for(int m = 0; m < n - 1; m++)
            cout << a[m] << ' ';
        cout << a[n - 1] << endl;
    }
}

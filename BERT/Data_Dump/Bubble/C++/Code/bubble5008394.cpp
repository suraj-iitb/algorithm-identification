#include <iostream>
using namespace std;

int number_of_swap = 0;

void bubble_sort(int a[], int n) {
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int j = n - 1; j >= 1; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                number_of_swap++;
                flag = 1;
            }
        }
    }
}

int main() {
    int n;
    int a[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bubble_sort(a, n);

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << a[i] << endl;
        } else {
            cout << a[i] << " ";
        }
    }
    cout << number_of_swap << endl;
    return 0;
}


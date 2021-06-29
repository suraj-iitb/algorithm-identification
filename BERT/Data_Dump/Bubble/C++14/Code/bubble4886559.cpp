#include <bits/stdc++.h>
using namespace std;

#define N 101

void print_list(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (i >= 1) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

int bubble_sort(int A[], int n) {
    int change_count = 0;
    bool change = true;
    int i = 0;
    while (change) {
        change = false;
        for (int j = n - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                change = true;
                change_count++;
            }
        }
        i++;
    }

    return change_count;
}

int main() {
    int n;
    cin >> n;
    int A[N];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count = bubble_sort(A, n);
    print_list(A, n);
    cout << count << endl;

    return 0;
}


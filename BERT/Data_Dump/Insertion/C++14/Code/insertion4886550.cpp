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

void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        print_list(A, n);
    }
}

int main() {
    int n;
    cin >> n;
    int A[N];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    print_list(A, n);
    insertion_sort(A, n);

    return 0;
}


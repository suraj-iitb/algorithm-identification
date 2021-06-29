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

int selection_sort(int A[], int n) {
    int change_count = 0;
    int i = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        int minv = A[i];
        for (int j = i + 1; j < n; j++) {
            if (A[j] < minv) {
                minj = j;
                minv = A[j];
            }
        }
        if (i != minj) {
            change_count++;
            int tmp = A[i];
            A[i] = minv;
            A[minj] = tmp;
        }
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

    int count = selection_sort(A, n);
    print_list(A, n);
    cout << count << endl;

    return 0;
}


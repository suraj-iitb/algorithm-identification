#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath> 
#include <cctype>

using namespace std;

int selectionSort(int A[], int N) {
    int minv, temp;
    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        minv = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minv]) {
                minv = j;
            }
        }
        temp    = A[i];
        A[i]    = A[minv];
        A[minv] = temp;
        if (i != minv) count++;
    }

    return count;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int count = selectionSort(A, N);

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << count << endl;
    return 0;
}

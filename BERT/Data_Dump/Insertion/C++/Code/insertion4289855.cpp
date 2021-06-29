#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath> 
#include <cctype>

using namespace std;

void print(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertsort(int A[], int N) {
    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print(A, N);
    }
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    print(A, N);
    insertsort(A, N);
    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

const int kSize = 100;
int n;

void Print(int A[kSize]) {
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << " ";
        }

        cout << A[i];
    }

    cout << endl;
}

int main() {
    cin >> n;
    int A[kSize];

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    Print(A);

    for (int i = 1; i < n; ++i) {
        int var = A[i];
        int j = i - 1;
        for (; j >= 0 && A[j] > var; --j) {
            A[j + 1] = A[j];
        }

        A[j + 1] = var;
        Print(A);
    }
}

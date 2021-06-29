#include <iostream>
#include <vector>

using namespace std;

void out(vector<uint16_t> A) {
    for (int i = 0; i < A.size() - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[A.size() - 1] << endl;
}

int
main(int argc, char** argv) {
    uint16_t n; cin >> n;
    vector<uint16_t> A(n);
    for (auto& a : A) {
        cin >> a;
    }
    for (uint16_t i = 1; i < n; i++) {
        out(A);
        auto v = A[i];
        auto j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
    out(A);
}

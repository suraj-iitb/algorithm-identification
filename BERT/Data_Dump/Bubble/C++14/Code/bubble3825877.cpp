#include <iostream>
#include <vector>

using namespace std;

uint16_t
bubblesort(vector<uint16_t>& A) {
    bool flag = true;
    uint16_t times = 0;
    while(flag) {
        flag = false;
        for(size_t j = A.size() - 1; j > 0; j--) {
            if (A[j] < A[j-1]) {
                uint16_t tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                ++times;
                flag = true;
            }
        }
    }
    return times;
}

void
out(const vector<uint16_t>& A) {
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
        cin >> a;                                                                                                                 }
    auto times = bubblesort(A);
    out(A);                                                                                                                       cout << times << endl;

}

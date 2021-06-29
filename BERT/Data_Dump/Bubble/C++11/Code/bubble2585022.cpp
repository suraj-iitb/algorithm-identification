#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        if (i == 0) {
            cout << A[i];
        } else {
            cout << ' ' << A[i];
        }
    }
    cout << endl;
}

void bubbleSort(vector<int>& A) {
    auto flag = true;
    auto swaps = 0;
    while (flag) {
        flag = false;
        for (auto j = A.size() - 1; j > 0; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = true;
                swaps++;
            }
        }
    }
    print(A);
    cout << swaps << endl;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;

    vector<int> a;
    a.reserve(n);

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a.push_back(val);
    }

    bubbleSort(a);

    return 0;
}

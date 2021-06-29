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

void insertionSort(vector<int>& A) {
    print(A);
    for (int i = 1; i < A.size(); i++) {
        auto v = A[i];
        auto j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print(A);
    }
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

    insertionSort(a);

    return 0;
}

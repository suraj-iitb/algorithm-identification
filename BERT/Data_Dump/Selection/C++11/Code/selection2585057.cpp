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

void selectionSort(vector<int>& A) {
    int swaps = 0;
    for (int i = 0; i < A.size(); i++) {
        int minj = i;
        for (int j = i; j < A.size(); j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            swaps++;
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

    selectionSort(a);

    return 0;
}

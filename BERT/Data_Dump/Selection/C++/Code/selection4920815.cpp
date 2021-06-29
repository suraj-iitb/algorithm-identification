#include <iostream>
#include <vector>
using namespace std;

int selectionSort(vector<int>& A) {
    int cnt = 0;

    for (int i = 0; i < A.size(); ++i) {
        int minj = i;
        for (int j = i; j < A.size(); ++j) {
            if (A[j] < A[minj]) 
                minj = j;
        }
        if (minj != i) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int N;
    vector<int> A;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int v;
        cin >> v;
        A.push_back(v);
    }

    int cnt = selectionSort(A);
    for (int i = 0; i < A.size() - 1; ++i) {
        cout << A[i] << " ";
    }
    cout << A.back() << endl;
    cout << cnt << endl;

    return 0;
}

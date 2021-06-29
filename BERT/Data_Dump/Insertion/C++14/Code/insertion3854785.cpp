#include <bits/stdc++.h>

using namespace std;

void print_vec(vector<int> &vec) {
    for (int j = 0; j < vec.size(); j++) {
        if (j != 0) cout << " ";
        cout << vec[j];
    }
    cout << endl;
}

int main() {
    int N;

    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    print_vec(A);
    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print_vec(A);
    }

    return 0;
}


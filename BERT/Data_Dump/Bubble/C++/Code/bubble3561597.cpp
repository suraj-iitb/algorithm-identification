#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main() {

    int N;
    cin >> N;

    int tmp;
    vi A;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }

    bool flag = true;
    int count = 0;
    while (flag) {
        flag = false;
        for (int j = N - 1; j > 0; j--) {
            if (A[j] < A[j - 1]) {
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                count++;
                flag = true;
            }
        }
    }

    for (int k = 0; k < N; k++) {
        cout << A[k];
        if (k != N - 1) {
            cout << " ";
        }
        else {
            cout << endl;
        }
    }

    cout << count << endl;

    return 0;
}


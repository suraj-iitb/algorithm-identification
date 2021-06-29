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

    int minj;
    for (int i = 0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) minj = j;
        }
        if (i != minj) {
            tmp = A[minj];
            A[minj] = A[i];
            A[i] = tmp;
            count++;
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


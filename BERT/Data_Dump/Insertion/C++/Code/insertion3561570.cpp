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

    for (int k = 0; k < N; k++) {
        cout << A[k];
        if (k != N - 1) {
            cout << " ";
        }
        else {
            cout << endl;
        }
    }
    int v, j;
    for (int i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        for (int k = 0; k < N; k++) {
            cout << A[k];
            if (k != N - 1) {
                cout << " ";
            }
            else {
                cout << endl;
            }
        }
    }

    return 0;
}


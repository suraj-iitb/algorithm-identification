#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }

    // output
    for (int i=0; i<N-1; i++) {
        cout << A.at(i) << " ";
    }
    cout << A.at(N-1) << endl;

    for (int i=1; i <= N-1; i++) {
        int v = A.at(i);
        int j = i - 1;
        while (j >= 0 && A.at(j) > v) {
            A.at(j+1) = A.at(j);
            j--;
        }
        A.at(j+1) = v;

        // output
        for (int i=0; i<N-1; i++) {
            cout << A.at(i) << " ";
        }
        cout << A.at(N-1) << endl;
    }

    return(0);
}

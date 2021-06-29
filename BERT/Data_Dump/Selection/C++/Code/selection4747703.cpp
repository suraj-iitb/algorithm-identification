#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        // find min
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A.at(minj) > A.at(j)) {
                minj = j;
            }
        }
        
        // swap
        if (i != minj) {
            int tmp = A.at(i);
            A.at(i) = A.at(minj);
            A.at(minj) = tmp;
            cnt++;
        }
    }

    // output
    for (int i=0; i<N-1; i++) cout << A.at(i) << " ";
    cout << A.at(N-1) << endl;
    cout << cnt << endl;

    return(0);
}

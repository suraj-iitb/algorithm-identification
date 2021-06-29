#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }

    int flag = 1, cnt = 0;
    int i = 0;
    while (flag) {
        flag = 0;
        for (int j = N-1; j >= i+1; j--) {
            if (A.at(j-1) > A.at(j)) {
                int tmp = A.at(j-1);
                A.at(j-1) = A.at(j);
                A.at(j) = tmp;

                flag = 1;
                cnt++;
            }
        }
        i++;
    }

    // output
    for (int i=0; i<N-1; i++) cout << A.at(i) << " ";
    cout << A.at(N-1) << endl;
    cout << cnt << endl;

    return(0);
}

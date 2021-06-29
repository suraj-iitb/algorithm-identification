//
// Created by yutaro_nishikawa on 2020/07/29.
//

#include <iostream>

using namespace std;
static const int MAX = 100;

int main() {
    int A[MAX], n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int cnt = 0;
    int flag = 1;
    for (int j = 0; flag; ++j) {
        flag = 0;
        for (int i = n - 1; i >= j + 1; --i) {
            if (A[i] < A[i - 1]) {
                int tmp = A[i - 1];
                A[i - 1] = A[i];
                A[i] = tmp;
                flag = 1;
                ++cnt;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << cnt << endl;

    return 0;

}

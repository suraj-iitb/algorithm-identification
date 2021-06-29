//
// Created by yutaro_nishikawa on 2020/07/28.
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

    for (int k = 0; k < n ; ++k) {
        if (k) cout << " ";
        cout << A[k];
    }
    cout << endl;

    for (int i = 1; i <= n - 1; ++i) {
        int insert_val = A[i];
        int j = i - 1;

        while (j >= 0 and A[j] > insert_val) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = insert_val;

        for (int k = 0; k < n ; ++k) {
            if (k) cout << " ";
            cout << A[k];
        }
        cout << endl;
    }

    return 0;
}

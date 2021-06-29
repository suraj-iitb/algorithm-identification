#include <iostream>

using namespace std;

static const int MAX = 100;

int main () {
        int i, j, n, A[MAX], min, idx, temp, c = 0;

        cin >> n;
        for (i = 0; i < n; i++)
                cin >> A[i];

        for (i = 0; i < n; i++) {
                min = A[i];
                idx = i;
                for (j = i + 1; j < n; j++) {
                        if (min > A[j]) {
                                min = A[j];
                                idx = j;
                        }
                }
                if (i != idx) {
                        temp = A[i];
                        A[i] = A[idx];
                        A[idx] = temp;
                        c++;
                }
        }

        cout << A[0];
        for (i = 1; i < n; i++)
                cout << ' ' << A[i];
        cout << endl;

        cout << c << endl;

        return 0;
}

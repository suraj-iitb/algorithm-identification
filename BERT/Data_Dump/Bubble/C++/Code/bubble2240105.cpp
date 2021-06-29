#include <iostream>

using namespace std;

static const int MAX = 100;

int main () {
        int n, i, j, A[MAX], temp, c = 0;

        cin >> n;
        for (i = 0; i < n; i++)
                cin >> A[i];

        for (i = 0; i < n; i++) {
                for (j = n - 1; j > i; j--) {
                        if (A[j] < A[j - 1]) {
                                        temp = A[j - 1];
                                        A[j - 1] = A[j];
                                        A[j] = temp;
                                        c++;
                                }
                }
        }

        //print Array
//      printf("%d", A[0]);
        cout << A[0];
        for (j = 1; j < n; j++) {
//              printf(" %d", A[j]);
                cout << ' ' << A[j];
        }
        cout << endl;

        cout << c << endl;

        return 0;
}

#include<iostream>

using namespace std;

int main () {

    int i, j, k, n, v, A[100];

    cin >> n;

    for (i = 0; i < n; i++) {

        cin >> A[i];

    }

    for (i = 0; i < n; i++) {

        cout << A[i];

        if (i < n - 1) {

            cout << " ";

        }

    }

    cout << endl;

    for (i = 1; i < n; i++) {

        v = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > v) {

            A[j + 1] = A[j];

            j--;

        }

        A[j + 1] = v;

        for (k = 0; k < n; k++) {

            cout << A[k];

            if (k < n - 1) {

                cout << " ";

            }

        }

        cout << endl;

    }

    return 0;

}

        

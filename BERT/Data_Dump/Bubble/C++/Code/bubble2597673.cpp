#include<iostream>
 
using namespace std;

int bubbleSort (int A[], int n) {

    int i = 0, j, v, count = 0;
    bool flag = 1;

    while (flag) {

        flag = 0;

        for (j = n - 1; j >= i + 1; j--) {

            if (A[j] < A[j - 1]) {

                v = A[j];
                A[j] = A[j - 1];
                A[j - 1] = v;


                flag = 1;

                count += 1;

            }

        }

    }

    return count;

}

int main () {
 
    int i, n, count, A[100];
 
    cin >> n;
 
    for (i = 0; i < n; i++) {
 
        cin >> A[i];
 
    }

    count = bubbleSort (A, n);

    for (i = 0; i < n; i++) {

        cout << A[i];

        if (i < n - 1) {

            cout << " ";

        }

    }

    cout << endl;
    cout << count << endl;

    return 0;

}

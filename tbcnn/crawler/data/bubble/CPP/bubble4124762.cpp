#include <iostream>

using namespace std;

int bubbleSort(int A[], int N) {
    bool flag = 1;
    int i = 0;

    while ( flag ) {
        flag = 0;
        for ( int j = N - 1; j > 0; j-- ) {
            if ( A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = 1;
                i++;
            }
        }
    }

    return i;
}
int main()
{
    int A[100], N;
    int sw;

    cin >> N;

    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }

    sw = bubbleSort(A, N);

    for ( int i = 0; i < N; i++ ) {
        if ( i > 0 )
            cout << " ";
        cout << A[i];
    }

    cout << endl;
    cout << sw << endl;

    return 0;
}


/*
 ALDS1_1_A
*/

#include <iostream>

using namespace std;

static const int MAX = 100;

void outArray(int N, const int (&A)[MAX]) {
    for(int i = 0; i < N; i++) {
        cout << A[i];
        if(i < N-1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int n, A[MAX];

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    outArray(n, A);

    for(int i = 1; i < n; i++) {
        int v = A[i];
        int j = i-1;
        while( (j >= 0) && (A[j] > v) ) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        outArray(n, A);
    }

}

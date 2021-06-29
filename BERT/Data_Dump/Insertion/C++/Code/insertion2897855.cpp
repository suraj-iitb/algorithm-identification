#include <iostream>
using namespace std;

static const int NMAX = 100;
static const int AMAX = 1000;

int main (void) {

    int N;
    int A[NMAX];

    cin >> N;
    for (int i=0; i < N; i++) cin >> A[i];

    for (int i=0; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while ((j >=0) && (A[j] > v)) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int k=0; k < N-1; k++) cout << A[k] << " ";
        cout << A[N-1] << endl;
    }
}

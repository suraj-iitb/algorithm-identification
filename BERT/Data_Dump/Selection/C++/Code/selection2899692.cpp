#include <iostream>
using namespace std;

static const int NMAX = 100;
static const int AMAX = 100;


void selectSort(const int N, int* A)
{
    int nswaps = 0;

    for (int i=0; i < N-1; i++) {
        int minj = i;
        for (int j = i+1; j < N; j++) {
            if ( A[j] < A[minj] ) {
                minj = j;
            }
        }
        if (minj != i) {
            int tmp = A[minj];
            A[minj] = A[i];
            A[i] = tmp;
            nswaps++;
        }
    }

    for (int k=0; k < N-1; k++) cout << A[k] << " ";
    cout << A[N-1] << endl;
    cout << nswaps << endl;
}

int main (void) {

    int N;
    int A[NMAX];

    cin >> N;
    for (int i=0; i < N; i++) cin >> A[i];
    
    selectSort(N, A);
}


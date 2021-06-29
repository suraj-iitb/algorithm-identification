#include <iostream>
using namespace std;

static const int NMAX = 100;
static const int AMAX = 1000;


void bubbleSort(const int N, int* A)
{
    int flag = 1;
    int nswaps = 0;

    while(flag) {
        flag = 0;
        for (int j=N-1; j > 0; j--) {
            if ( A[j] < A[j-1] ) {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                nswaps++;
            }
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
    
    bubbleSort(N, A);
}


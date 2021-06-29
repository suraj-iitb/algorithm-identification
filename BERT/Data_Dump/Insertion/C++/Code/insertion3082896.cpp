#include <iostream>

static const int N = 1000;

void trace(int A[N], int n) {
    int i;
    for ( i = 0; i < n; i++ ){
        if ( i > 0 ) std::cout << " ";
        std::cout << A[i];
    }
    std::cout << std::endl;
}

int main(void) {
    int n;
    int A[N];
    std::cin >> n;
    for (int i=0; i<n; ++i) {
        std::cin >> A[i];
    }
    trace(A, n);

    for (int i=1; i<n; ++i) {
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        trace(A, n);
    }
}


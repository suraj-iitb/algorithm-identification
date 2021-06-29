#include <iostream>
using namespace std;

#define rep(s, e) for(int i(s); i < e; ++i)
#define MAX_NUMBER_OF_A 100

void insertion_sort(int[], int);
void peek(int[], int);

int main() {
    int *A = new int[100];
    rep(0, MAX_NUMBER_OF_A) {
        A[i] = 0;
    }
    
    int n(0);
    cin >> n;
    rep(0, n) {
        cin >> A[i];
    }

    peek(A, n);

    insertion_sort(A, n);
    return 0;
}

void peek(int A[], int n) {
    rep(0, n) {
        if(i != 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << "\n";
}

void insertion_sort(int A[], int n) {
    rep(1, n) {
        int v(A[i]);
        int j(i-1);
        while( j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j -= 1;
        }
        A[j+1] = v;
        peek(A, n);
    }
}

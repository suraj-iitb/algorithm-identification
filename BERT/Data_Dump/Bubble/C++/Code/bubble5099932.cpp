#include <iostream>
using namespace std;

void trace(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i];
        if(i != n - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    bool is_continue = true;
    int i = 0;
    int sw = 0;
    while(is_continue) {
        is_continue = false;
        for(int j = n - 1; j > i; j--) {
            if(A[j - 1] > A[j]) {
                swap(A[j - 1], A[j]);
                is_continue = true;
                sw++;
            }
        }
        i++;
    }

    trace(A, n);
    cout << sw << endl;

    return 0;
}

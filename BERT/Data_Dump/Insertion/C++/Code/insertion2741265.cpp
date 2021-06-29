#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // input
    int N, A[110];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    for (int i = 1; i < N; i++) {
        
        // print loop
        for (int e = 0; e < N; e++) {
            if (e > 0) cout << " ";
            cout << A[e];
        }
        cout << endl;
        
        // sorting algorithm    
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
    
    // result array output
    for (int e = 0; e < N; e++) {
        if (e > 0) cout << " ";
        cout << A[e];
    }
    cout << endl;
    return 0;
}


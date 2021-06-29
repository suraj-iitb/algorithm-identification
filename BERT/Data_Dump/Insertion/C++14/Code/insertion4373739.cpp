#include <iostream>
using namespace std;

int main(void) {
    int N;cin>>N;
    int A[N];
    for (int i = 0; i < N; i++) cin>>A[i];
        for (int i = 0; i < N; i++) {
            cout << A[i];
            if (i < N - 1) cout << " ";
        }
        cout << endl;
    for (int i = 1; i < N; i++) {
        int val = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > val) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = val;
        for (int i = 0; i < N; i++) {
            cout << A[i];
            if (i < N - 1) cout << " ";
        }
        cout << endl;
    }    
    return 0;
}

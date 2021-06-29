#include<iostream>
using namespace std;

int main () {
    int N, A[100];
    int count = 0;
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    
    for(int i = 0; i < (N - 1); i++) {
        for(int j = (N - 1); j > i; j--) {
            if(A[j] < A[j - 1]) {
                int k = A[j];
                A[j] = A[j - 1];
                A[j - 1] = k;
                count++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(i < N-1) cout << A[i] << " ";
        else cout << A[i] <<"";
    }
    cout << endl;
    cout << count << endl;

    return 0;
}

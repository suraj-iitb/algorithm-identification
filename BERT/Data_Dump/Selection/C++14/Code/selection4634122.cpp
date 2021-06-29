#include <iostream>
using namespace std;

int main(){
    int N, A[100];
    int count = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    for (int i = 0; i < N - 1; i++) {
        int m = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[m]) {
                m = j;
            }
        }
        int min = A[m];
        A[m] = A[i];
        A[i] = min;
        if(A[m] != A[i]) count++;

    }

    for (int i = 0; i < N; i++) {
        if(i < N-1) cout << A[i] << " ";
        else cout << A[i] << "";
    }
    cout << endl;
    cout << count << endl;

    return 0;
}

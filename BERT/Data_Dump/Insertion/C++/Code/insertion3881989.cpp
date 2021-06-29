#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int (i)=0;(i)<(n);(i)++)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    
    REP(i, N) {
        int temp = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            A[j] = temp;
            j--;
        }
        REP(k, N-1) {
            cout << A[k] << " ";
        }
        cout << A[N-1] << endl;
    }
}

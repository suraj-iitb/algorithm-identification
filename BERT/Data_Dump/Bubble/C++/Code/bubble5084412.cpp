#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, cnt=0;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin >> A[i];
    
    bool flag = true;
    int tmp;
    while (flag) {
        flag = false;
        for (int j=N-1; j>=1; j--) {
            if (A[j] < A[j-1]) {
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = true;
                cnt++;
            }
        }
        
    }
    
    for (int i=0; i<N-1; i++) cout << A[i] << ' ';
    cout << A[N-1] << endl;
    cout << cnt << endl;
}

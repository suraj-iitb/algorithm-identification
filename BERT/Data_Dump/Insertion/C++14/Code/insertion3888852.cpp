#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;

i32 main() {
    i32 N; cin >> N;
    i32 A[N];
    for (i32 i = 0; i < N; i++) cin >> A[i], cout << (i == 0 ? "" : " ") << A[i];
    cout << "\n";
    
    for (i32 i = 1; i <= N - 1; i++) {
        i32 v = A[i];
        i32 j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (i32 i = 0; i < N; i++) cout << (i == 0 ? "" : " ") << A[i];
        cout << endl;
    }
    
    return 0;
}

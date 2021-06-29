#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; ++i) cin >> A[i];
    
    int swp;
    int cnt = 0;
    for (int i=0; i<N; ++i) {
        for (int j=N-1; j>i; --j) {
            if (A[j-1] > A[j]) {
                swp = A[j-1];
                A[j-1] = A[j];
                A[j] = swp;
                ++cnt;
            }
        }
    }
    for (int i=0; i<N-1; ++i) cout << A[i] << " ";
    cout << A.back() << "\n" << cnt << "\n";
    return 0;
}

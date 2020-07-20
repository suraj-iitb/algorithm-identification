    #include <iostream>
    #include <algorithm>
    using namespace std;
    
    int main() {
        int N; cin >> N;
        int A[N];
        for (int i = 0; i < N; ++i) cin >> A[i];
        bool f = 1;
        int count = 0;
        while(f) {
            f = 0;
            for (int i = 0; i < N-1; ++i ) {
                if (A[i] > A[i+1]) {
                    swap(A[i], A[i+1]);
                    f = 1;
                    ++count;
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << A[i];
        }
        cout << endl;
        cout << count << endl;
        return 0;
    }

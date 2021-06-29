    #include <iostream>
    using namespace std;
    
    int main() {
        int N; cin >> N;
        int A[N];
        for (int i = 0; i < N; ++i) cin >> A[i];
        
        int count = 0;
        for (int i = 0; i < N-1; ++i) {
            int min = i;
            for (int j = i + 1; j < N; ++j) {
                if (A[j] < A[min]) min = j;
            }
            if (i != min) {
                swap(A[i], A[min]);
                ++count;
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

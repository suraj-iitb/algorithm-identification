# include <iostream>
using namespace std;

int n, ch_cnt = 0;

int main() {
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    
    for (int i = 0; i < n; i++) {
        int minj = i;
        
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) ch_cnt++;
        swap(A[i], A[minj]);
    }
    
    for (int i = 0; i < n - 1; i++) cout << A[i] << " ";
    cout << A[n - 1] << endl;
    cout << ch_cnt << endl;
        
    return 0;
}

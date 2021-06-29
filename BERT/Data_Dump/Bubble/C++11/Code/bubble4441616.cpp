# include <iostream>
using namespace std;

int N, sort_cnt = 0;

int main() {
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];
    
    int flag = 1; // 隣接要素が存在する
    while (flag) {
        flag = 0;
        
        for (int j = N - 1; j >= 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = 1;
                sort_cnt++;   
            }
        }
    }
    
    for (int i = 0; i < N - 1; i++) cout << A[i] << " ";
    cout << A[N - 1] << endl;
    cout << sort_cnt << endl;
    
    return 0;
}

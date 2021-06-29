#include<iostream>
using namespace std;

int main(void){
    int N, ans = 0;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    for (int i = 0; i < N; i++){
        int minj = i;
        for (int j = (i + 1); j < N; j++){
            if (A[j] < A[minj]) minj = j;
        }
        if (minj != i){
            int v = A[minj];
            A[minj] = A[i];
            A[i] = v;
            ans++;
        }
    }

    for (int i = 0; i < N; i++){
        cout << A[i];
        if (i != (N - 1)) cout << ' ';
        else cout << endl;
    }

    cout << ans << endl;

    return 0;
}

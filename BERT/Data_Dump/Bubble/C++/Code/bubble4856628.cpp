#include <iostream>
using namespace std;

void bubbleSort(int V[], int N) {
    int cnt = 0;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = N-1; i > 0; --i) {
            if (V[i-1] > V[i]) {
                swap(V[i-1], V[i]);
                cnt++;
                flag = 1 ;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i==N-1) cout << V[i] << "\n";
        else cout << V[i] << " ";
    }
    cout << cnt << "\n";
}


int main() {
    
    int V[100];

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    bubbleSort(V, N);

    return 0;
}

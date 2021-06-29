#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (data[j] < data[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            count++;
        }
        swap(data[i], data[minj]);
    }
    for (int i = 0; i < N; i++) {
        if (i == N-1) {
            cout << data[i] << endl;
            break;
        }
        else {
            cout << data[i] << " ";
        }
    }
    cout << count <<endl;
}

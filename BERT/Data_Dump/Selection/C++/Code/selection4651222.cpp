#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(i > 0) cout << " ";
        cout << vec.at(i);
    }
    cout << endl;
}

int selectionSort(vector<int> &A, int N) {
    int minj;
    int sw = 0;
    for(int i = 0; i < N; i++) {
        minj = i;
        for(int j = i; j < N; j++) {
            if(A.at(j) < A.at(minj)) {
                minj = j;
            }
        }
        swap(A.at(i), A.at(minj));
        if(i != minj) {
            sw++;
        }
    }
    return sw;
}

int main() {
    int N, ans;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    ans = selectionSort(A, N);
    trace(A);
    cout << ans << endl;
}

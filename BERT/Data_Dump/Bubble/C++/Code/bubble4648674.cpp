#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(i > 0) cout << " ";
        cout << vec.at(i);
    }
    cout << endl;
}

int bubbleSort(vector<int> &A, int N) {
    int count = 0;
    bool flag = true;
    int i = 0;
    while(flag) {
        flag = false;
        for(int j = N - 1; j > i; j--) {
            if(A.at(j) < A.at(j - 1)) {
                swap(A.at(j), A.at(j - 1));
                count++;
                flag = true;
            }
        }
        i++;
    }
    return count;
}

int main() {
    int N, ans;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    ans = bubbleSort(A, N);
    trace(A);
    cout << ans << endl;
}

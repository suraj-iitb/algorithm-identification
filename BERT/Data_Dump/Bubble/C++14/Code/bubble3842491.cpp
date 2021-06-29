#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int> &A, int N) {
    bool flag = 1;
    int count = 0;
    while (flag) {
        flag = 0;
        for (int j = N -1; j > 0; j--) {
            if (A.at(j) < A.at(j-1)) {
                int v = A.at(j);
                A.at(j) = A.at(j-1);
                A.at(j-1) = v;
                count++;
                flag = 1;
            }
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data.at(i);
    }
    int a = bubbleSort(data, n);
    for (int i = 0; i < n; i++) {
        if (i == n-1) {
            cout << data.at(i) << endl;
        } else {
            cout << data.at(i) << " " ;
        }
    }
    cout << a << endl;     
    return 0;
}


#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    int cnt = 0;
    int minj;
    for (int i = 0; i < n; i++) {
        minj = i;
        for (int j = i; j < n; j++) {
            if (data[j] < data[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            cnt++;
            swap(data[minj], data[i]);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << data[i] << " ";
    }
    cout << data[n - 1] << endl;
    cout << cnt << endl;

    return 0;
}

#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int cnt = 0;
    bool flag = 1;
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = n - 1; j > i; j--) {
            if (vec[j] < vec[j - 1]) {
                swap(vec[j], vec[j - 1]);
                flag = 1;
                cnt++;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << vec[i] << " ";
    }
    cout << vec[n - 1] << endl;
    cout << cnt << endl;

    return 0;
}

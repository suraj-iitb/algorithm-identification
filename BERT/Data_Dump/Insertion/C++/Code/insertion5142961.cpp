#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int n, v;
    cin >> n;
    vector <int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        v = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] > v) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = v;
        for (int k = 0; k < n - 1; k++) {
            cout << vec[k] << " ";
        }
        cout << vec[n - 1] << endl;
    }

    return 0;
}

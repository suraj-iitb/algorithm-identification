#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data.at(i);
    }

    for (int i = 0; i < data.size(); i++) {
        if (i == data.size() - 1) {
            cout << data.at(i) << endl;
        } else {
            cout << data.at(i) << " ";
        }
    }
    for (int i = 1; i < data.size(); i++) {
        int v = data.at(i);
        int j = i -1;
        while (j >= 0 && v < data.at(j)) {
            data.at(j + 1) = data.at(j);
            j--;
            }
        data.at(j + 1) = v;
        for (int i = 0; i < data.size(); i++) {
            if (i == data.size() - 1) {
                cout << data.at(i) << endl;
            } else {
                cout << data.at(i) << " ";
            }
        }
            }
    
}

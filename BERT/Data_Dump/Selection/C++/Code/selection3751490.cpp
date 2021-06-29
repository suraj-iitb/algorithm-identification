#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a.at(j) < a.at(minj)) minj = j;
        }
        if (a.at(i) != a.at(minj)) {
            swap(a.at(i), a.at(minj));
            count++;   
        }
    }

    for (int x = 0; x < n; x++) {
        if (x) cout << " ";
        cout << a.at(x);
    }
    cout << endl;
    cout << count << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    selectionSort(a, n);

    return 0;
}

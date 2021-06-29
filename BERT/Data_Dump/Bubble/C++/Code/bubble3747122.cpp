#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> a, int n) {
    bool flag = true;
    int i = 0;
    int count = 0;
    while (flag) {
        flag = false;
        for (int j = n-1; j > i; j--) {
            if (a.at(j) < a.at(j-1)) {
                swap(a.at(j), a.at(j-1));
                flag = true;
                count++;
            }
        }
        i++;
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
    for (int x = 0; x < n; x++) {
        cin >> a.at(x);
    }
    bubbleSort(a, n);

     return 0;
}

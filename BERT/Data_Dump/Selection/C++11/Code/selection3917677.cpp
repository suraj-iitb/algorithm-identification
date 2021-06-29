/*
    Selection Sort
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_2_B
*/
#include <bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &vi) {
    int cnt = 0;
    int len = vi.size();
    for (int i = 0; i < len; i++) {
        int minj = i;
        for (int j = i; j < len; j++) {
            if (vi[j] < vi[minj]) {
                minj = j;
            }
        }
        swap(vi[i], vi[minj]);
        if (i != minj) {
            cnt++;
        }
    }

    // result
    for (size_t i = 0; i < vi.size(); i++) {
        cout << vi[i];
        cout << ((i != vi.size() - 1) ? " " : "\n");
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> vi(n);

    for (int i = 0; i < n; i++) {
        cin >> vi[i];
    }

    SelectionSort(vi);
}

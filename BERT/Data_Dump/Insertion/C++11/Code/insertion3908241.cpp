#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> &vi) {
    for (size_t i = 0; i < vi.size(); i++) {
        cout << vi[i];
        cout << ((i != vi.size() - 1) ? " " : "\n");
    }
}

void insertionSort(vector<int> &vi) {
    int v = 0;
    trace(vi);
    for (size_t i = 1; i < vi.size(); i++) {
        v = vi[i];
        int j = i - 1;
        while (j >= 0 && vi[j] > v) {
            vi[j + 1] = vi[j];
            j--;
        }
        vi[j + 1] = v;
        trace(vi);
    }
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
    insertionSort(vi);
}

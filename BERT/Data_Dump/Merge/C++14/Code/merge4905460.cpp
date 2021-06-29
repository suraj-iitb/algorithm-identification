#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

void merge(vector<int> &left, vector<int> &right, vector<int> &merged_a, int &cnt) {
    int i = 0, j = 0;
    while (i < left.size() || j < right.size()) {
        if ((i < left.size() && left[i] < right[j]) || j == right.size()) {
            merged_a[i+j] = left[i];
            i++;
        } else {
            merged_a[i+j] = right[j];
            j++;
        }
        cnt++;
    }
}

void merge_sort(vector<int> &a, int &cnt) {
    if (a.size() > 1) {
        int left_size = a.size() / 2;
        int right_size = a.size() - left_size;
        vector<int> left(left_size);
        vector<int> right(right_size);
        rep(i, left_size) {
            left[i] = a[i];
        }
        rep(i, right_size) {
            right[i] = a[left_size + i];
        }
        merge_sort(left, cnt);
        merge_sort(right, cnt);
        merge(left, right, a, cnt);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int cnt = 0;
    merge_sort(a, cnt);
    rep(i, n) {
        cout << (i ? " " : "") << a[i];
    }
    cout << endl;
    cout << cnt << endl;
}

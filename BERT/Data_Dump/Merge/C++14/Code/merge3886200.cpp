#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// merge v[left] to v[mid-1] and v[mid] to v[right-1]
int merge(vector<int>& v, int left, int mid, int right) {
    vector<int> l(mid - left + 1);
    for (int i = 0; i < l.size() - 1; ++i)
        l[i] = v[i + left];
    vector<int> r(right - mid + 1);
    for (int i = 0; i < r.size() - 1; ++i)
        r[i] = v[i + mid];

    l[l.size() - 1] = INT_MAX;
    r[r.size() - 1] = INT_MAX;

    int idx_left = 0;
    int idx_right = 0;
    int compare_count = 0;
    for (int i = left; i < right; ++i) {
        if (l[idx_left] < r[idx_right]) {
            v[i] = l[idx_left];
            ++idx_left;
        } else {
            v[i] = r[idx_right];
            ++idx_right;
        }
        ++compare_count;
    }

    return compare_count;
}

// sort v[left] to v[right-1] with merge sort algorithm
// v[right] will not be modified
int _merge_sort(vector<int>& v, int left, int right) {
    int count = 0;

    if (left + 1 < right) {
        int mid = left + (right - left) / 2;
        count += _merge_sort(v, left, mid);
        count += _merge_sort(v, mid, right);
        count += merge(v, left, mid, right);
    }

    return count;
}

int merge_sort(vector<int>& v) { return _merge_sort(v, 0, v.size()); }

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    int count = merge_sort(s);

    cout << s[0];
    for (int i = 1; i < n; ++i)
        cout << ' ' << s[i];
    cout << '\n';

    cout << count << '\n';
}


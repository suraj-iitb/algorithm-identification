#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& v, int left, int mid, int right)
{
    vector<int> l(mid - left + 1);
    vector<int> r(right - mid);

    for (int i = 0; i < l.size(); ++i)
        l[i] = v[left+i];
    for (int i = 0; i < r.size(); ++i)
        r[i] = v[mid+1+i];

    int compare_count = 0;
    int idx = 0;
    int l_idx = 0;
    int r_idx = 0;
    while (l_idx < l.size() && r_idx < r.size()) {
        if (l[l_idx] <= r[r_idx]) {
            v[left+idx] = l[l_idx];
            ++l_idx;
        } else {
            v[left+idx] = r[r_idx];
            ++r_idx;
        }
        ++idx;
        ++compare_count;
    }
    while (l_idx < l.size()) {
        v[left+idx] = l[l_idx];
        ++l_idx;
        ++idx;
        ++compare_count;
    }
    while (r_idx < r.size()) {
        v[left+idx] = r[r_idx];
        ++r_idx;
        ++idx;
        ++compare_count;
    }
    return compare_count;
}

int merge_sort(vector<int>& v, int left, int right)
{
    int compare_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        compare_count += merge_sort(v, left, mid);
        compare_count += merge_sort(v, mid+1, right);
        compare_count += merge(v, left, mid, right);
    }
    return compare_count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    int compare_count = merge_sort(s, 0, n-1);

    cout << s[0];
    for (int i = 1; i < n; ++i)
        cout << ' ' << s[i];
    cout << '\n';
    cout << compare_count << '\n';
}


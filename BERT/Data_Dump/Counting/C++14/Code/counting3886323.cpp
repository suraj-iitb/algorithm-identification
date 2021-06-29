#include <iostream>
#include <vector>

using namespace std;

void counting_sort(vector<int>& v) {
    vector<int> count(10001, 0);
    vector<int> tmp(v.size());
    for (int i = 0; i < v.size(); ++i) {
        tmp[i] = v[i];
        ++count[v[i]];
    }

    for (int i = 1; i < count.size(); ++i)
        count[i] = count[i - 1] + count[i];

    for (int i = v.size() - 1; i >= 0; --i) {
        v[count[tmp[i]] - 1] = tmp[i];
        --count[tmp[i]];
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    counting_sort(a);

    cout << a[0];
    for (int i = 1; i < n; ++i)
        cout << ' ' << a[i];
    cout << '\n';
}


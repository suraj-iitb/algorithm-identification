#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int selection_sort(vector<int>& v, int length) {
    int count = 0;

    for (int i = 0; i < length; ++i) {
        int min_idx = i;
        for (int j = i; j < length; ++j) {
            if (v[min_idx] > v[j])
                min_idx = j;
        }
        if (i != min_idx) {
            swap(v[i], v[min_idx]);
            ++count;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int count = selection_sort(v, n);

    cout << v[0];
    for (int i = 1; i < n; ++i)
        cout << ' ' << v[i];
    cout << '\n';

    cout << count << '\n';
}


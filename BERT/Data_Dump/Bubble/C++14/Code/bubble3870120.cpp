#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int bubble_sort(vector<int>& v, int length) {
    int count = 0;
    bool flag = true;

    while (flag) {
        flag = false;
        for (int j = length - 1; j > 0; --j) {
            if (v[j] < v[j - 1]) {
                swap(v[j], v[j - 1]);
                flag = true;
                ++count;
            }
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

    int count = bubble_sort(v, n);

    cout << v[0];
    for (int i = 1; i < n; ++i)
        cout << ' ' << v[i];
    cout << '\n';

    cout << count << '\n';
}


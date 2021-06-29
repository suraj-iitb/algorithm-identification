#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int>& v, int length) {
    cout << v[0];
    for (int i = 1; i < length; ++i)
        cout << ' ' << v[i];
    cout << '\n';
}

void insertion_sort(vector<int>& v, int length) {
    print_vector(v, length);

    for (int i = 1; i < length; ++i) {
        int tmp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > tmp) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = tmp;

        print_vector(v, length);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    insertion_sort(v, n);
}


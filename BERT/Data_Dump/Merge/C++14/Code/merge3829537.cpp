#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> V;

int merge(V &s, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    V l = V(n1);
    V r = V(n2);
    for (int i = 0; i < n1; i++) {
        l[i] = s[left + i];
    }
    for (int i = 0; i < n2; i++) {
        r[i] = s[mid + i];
    }
    int i = 0, j = 0, c = 0;
    for (int k = left; k < right; k++) {
        if (j >= r.size() || (i < l.size() && l[i] <= r[j])) {
            s[k] = l[i++];
        } else {
            s[k] = r[j++];
        }
        c++;
    }
    return c;
}

int merge_sort(V &s, int left, int right) {
    int c = 0;
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        c += merge_sort(s, left, mid);
        c += merge_sort(s, mid, right);
        c += merge(s, left, mid, right);
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    V s = V(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int c = merge_sort(s, 0, s.size());
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << s[i];
    }
    cout << "\n" << c << "\n";
}

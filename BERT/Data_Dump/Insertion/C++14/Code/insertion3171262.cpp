#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void printvec(vi& a, int n) {
    cout << a.front();
    for (int i = 1; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
}

void insertionsort(vi& a, int n) {
    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        printvec(a, n);
    }
}

int main() {
    int n;
    vi as;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        as.push_back(a);
    }
    printvec(as, n);
    insertionsort(as, n);
}

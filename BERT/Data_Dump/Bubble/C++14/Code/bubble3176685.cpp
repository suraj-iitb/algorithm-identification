#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

int bubbleSort(vi& a) {
    bool change = 1;
    int cnt = 0;
    while (change) {
        change = 0;
        for (int j = a.size() - 1; j >= 1; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                cnt++;
                change = 1;
            }
        }
    }
    return cnt;
}

void printvec(vi& x, int size = 0) {
    cout << x.front();
    for (int i = 1; i < (size == 0 ? x.size() : size); i++) {
        cout << " " << x[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vi as;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        as.push_back(a);
    }

    int cnt = bubbleSort(as);
    printvec(as);
    cout << cnt << endl;
}

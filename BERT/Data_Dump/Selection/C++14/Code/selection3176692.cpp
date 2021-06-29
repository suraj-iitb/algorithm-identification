#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

int selectionSort(vi& a) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        int minj = i;
        for (int j = i; j < a.size(); j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(a[i], a[minj]);
            cnt++;
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
    int cnt = selectionSort(as);
    printvec(as);
    cout << cnt << endl;
}

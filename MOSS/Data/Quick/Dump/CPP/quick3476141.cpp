// std = C++14
#include <iostream> // cin, cout, endl, ...
using namespace std;

class card {
public:
    char moji;
    int num, id; 
};
// IDを追加
//   ref: https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_6_C/review/970351/dohatsu/C++

int partition(card* C, int p, int r) {
    const int x = C[r].num;
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
        if (C[j].num <= x) {
            i++;
            swap(C[i], C[j]);
        }
    swap(C[i + 1], C[r]);
    return i + 1;
}

void quick_sort(int n, card* C, int p, int r) {
    if (p < r) {
        const int q = partition(C, p, r);
        quick_sort(n, C, p, q - 1);
        quick_sort(n, C, q + 1, r);
    }
}

bool is_stable(int n, card* C) {
    for (int i = 1; i <= n - 1; i++)
        if (C[i].num == C[i - 1].num && C[i].id < C[i - 1].id)
            return false;
    return true;
}

int main() {
    int n; cin >> n;
    card Cards[n];
    for (int i = 0; i < n; i++) {
        cin >> Cards[i].moji >> Cards[i].num;
        Cards[i].id = i;
    }

    quick_sort(n, Cards, 0, n - 1);

    if (is_stable(n, Cards))
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
    for (int i = 0; i < n; i++)
        cout << Cards[i].moji << ' ' << Cards[i].num << endl;
}

#include <bits/stdc++.h>

using namespace std;
typedef pair<char, int> P;

int n;
P card[100010], cpy[100010];

int partition(int p, int r) {
    int x = card[r].second, i = p - 1;
    for (int j = p; j < r; j++) {
        if (card[j].second > x) continue;
        i++;
        swap(card[i], card[j]);
    }
    swap(card[i + 1], card[r]);
    return i + 1;
}

void quickSort(int p, int r) {
    if (p >= r) return;
    int q = partition(p, r);
    quickSort(p, q - 1);
    quickSort(q + 1, r);
}

bool comp(const P& p1, const P& p2) {
    return p1.second < p2.second;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> card[i].first >> card[i].second;
        cpy[i] = card[i];
    }

    quickSort(0, n - 1);
    stable_sort(cpy, cpy + n, comp);

    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (card[i] == cpy[i]) continue;
        flag = true;
    }

    if (flag) cout << "Not stable\n";
    else cout << "Stable\n";
    
    for (int i = 0; i < n; i++)
        cout << card[i].first << " " << card[i].second << endl;

    return 0;
}

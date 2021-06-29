#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int q = 0;
void merge(auto v, auto l, auto m, auto r) {
    auto n1 = m - l;
    auto n2 = r - m;
    vector<int> L(n1 + 1), R(n2 + 1);
    for (int i = 0; i < n1; i++) L[i] = v[l + i];
    for (int i = 0; i < n2; i++) R[i] = v[m + i];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    
    int i = 0;
    int j = 0;
    for (int k = l; k < r; k++) {
        if (L[i] <= R[j]) { v[k] = L[i++]; q++; }
        else { v[k] = R[j++]; q++; } 
    }
}

void merge_sort(int v[], auto l, auto r) {
    if (l + 1 < r) {
        auto m = (l + r) / 2;
        merge_sort(v, l, m);
        merge_sort(v, m, r);
        merge(v, l, m, r);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n;
    int v[600000];
    for (int i = 0; i < n; i++) { cin >> v[i]; }
    merge_sort(v, 0, n);
    for (int i = 0; i < n - 1; i++) { cout  << v[i] << " "; }
    cout << v[n - 1] << "\n";
    cout << q << "\n";
    return 0;
}

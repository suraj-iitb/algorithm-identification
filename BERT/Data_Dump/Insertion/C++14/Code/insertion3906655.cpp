#include<bits/stdc++.h>
#define pb push_back
#define N 200000000

using namespace std;

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) cout << v[i] << "\n";
        else cout << v[i] << " ";
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, o;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> o; v.pb(o); }
    print(v);

    for (int i = 1; i < n; i++) {
        int k = v[i];
        int j = i -1;
        while (j >= 0 && v[j] > k) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = k;
        print(v);
    }


    return 0;
}


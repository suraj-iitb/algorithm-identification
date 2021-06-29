#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void show(vector<int> a, int N) {
    rep(i, N - 1) cout<<a[i]<<" ";
    cout<<a[N - 1]<<endl;
}

void insertionSort(vector<int> a, int N) {
    rep(i, N) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;

        show(a, N);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;
    vector<int> a(N);
    rep(i, N) cin>>a[i];

    insertionSort(a, N);
}


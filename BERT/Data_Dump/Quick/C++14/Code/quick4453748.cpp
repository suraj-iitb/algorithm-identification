#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
template <class T>
bool chmax(T &a, const T &b) { return (a < b) ? (a = b, 1) : 0; }
template <class T>
bool chmin(T &a, const T &b) { return (b < a) ? (a = b, 1) : 0; }

#define MAX 100005
 
typedef long long ll;
typedef pair<int, int> P;

struct CARD {
    char sort;
    int num;
    bool operator==(const CARD &c) const { return sort == c.sort && num == c.num; };
    bool operator!=(const CARD &c) const { return sort != c.sort || num != c.num; };
    bool operator<(const CARD &c) const { return num < c.num; };
    bool operator<=(const CARD &c) const { return num <= c.num; };
    CARD(char sort, int num) { this->sort = sort; this->num = num; };
};

template <class T>
int partition(vector<T> &a, int p, int r)
{
    T x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j] <= x) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[r], a[i+1]);
    return i+1;
}

template <class T>
void QuickSort(vector<T> &a, int p, int r)
{
    if (p >= r) return;
    int q = partition(a, p, r);
    QuickSort(a, p, q-1);
    QuickSort(a, q+1, r); 
}

int main(int, char**)
{
    int n;
    cin >> n;

    vector<CARD> a;
    char s;
    int t;
    rep(i,n) {
        cin >> s >> t;
        a.emplace_back(s, t);
    }
    vector<CARD> a2 = a;
    QuickSort(a, 0, n-1);
    stable_sort(a2.begin(), a2.end());

    bool stb = true;
    rep(i,n) if (a[i] != a2[i]) stb = false;
    cout << (stb ? "Stable" : "Not stable") << endl;
    rep(i,n) cout << a[i].sort << " " << a[i].num << endl;

    return 0;
}

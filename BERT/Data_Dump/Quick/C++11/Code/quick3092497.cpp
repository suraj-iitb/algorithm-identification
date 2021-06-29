#include <bits/stdc++.h>
using namespace std;

int partition(pair<int, char> a[], int p, int r)
{
    int x = a[r].first;
    int i = p - 1;

    for(int j = p; j < r; j++) {
        if (a[j].first <= x) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);

    return i + 1;
}

void quicksort(pair<int, char> a[], int p, int r)
{
    if (p < r){
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

bool comp(pair<int, char> a, pair<int, char> b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;

    pair<int, char> a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i].second >> a[i].first, b[i] = a[i];

    quicksort(a, 0, n - 1);

    stable_sort(b, b + n, comp);

    bool f = true;
    for(int i = 0; i < n; i++) {
        // cerr << b[i].second << " " << b[i].first << " " << a[i].second << " " << a[i].first << endl;
        if(b[i] != a[i]) f = false;
    }
    cout << (f ? "Stable" : "Not stable") << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i].second << " " << a[i].first << endl;
    }

    return 0;
}


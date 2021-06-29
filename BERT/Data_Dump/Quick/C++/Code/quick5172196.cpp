#include <iostream>
using namespace std;
#define MAX 100000
struct card {
    char suit;
    int value;
};
card a[MAX], b[MAX], tmp[MAX];

void swap(card &a, card &b)
{
    card tmp = a;
    a = b;
    b = tmp;
}

void merge(int l, int m, int r)
{
    int pb = 0, p1 = l, p2 = m + 1;
    while (p1 <= m && p2 <= r)
    {
        if (a[p1].value <= a[p2].value) tmp[pb++] = a[p1++];
        else tmp[pb++] = a[p2++];
    }
    while (p1 <= m) tmp[pb++] = a[p1++];
    while (p2 <= r) tmp[pb++] = a[p2++];
    for (int i = 0; i < r - l + 1; ++i)
        a[l + i] = tmp[i];
}

void mergesort(int l, int r)
{
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergesort(l, mid);
        mergesort(mid + 1, r);
        merge(l, mid, r);
    }
}

int partition(card b[], int l, int r)
{
    int x = b[r].value;
    int p = l - 1;
    for (int j = l; j < r; ++j)
    {
        if (b[j].value <= x) {
            ++p;
            swap(b[p], b[j]);
        }
    }
    swap(b[r], b[p + 1]);
    return p + 1;
}

void quicksort(card b[], int l, int r)
{
    if (l < r) {
        int i = partition(b, l, r);
        quicksort(b, l, i - 1);
        quicksort(b, i + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    bool stable = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].suit >> a[i].value;
        b[i].suit = a[i].suit;
        b[i].value = a[i].value;
    }
    mergesort(0, n - 1);
    quicksort(b, 0, n - 1);
    for (int i = 0; i < n; ++i)
        if (a[i].suit != b[i].suit) {
            stable = false;
            break;
        }
    cout << ((stable) ? "Stable" : "Not stable") << endl;
    for (int i = 0; i < n; ++i)
        cout << b[i].suit << " " << b[i].value << endl;
    return 0;
}

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Card {
    char c;
    int n;
};

// merge v[left] to v[mid-1] and v[mid] to v[right-1]
int merge(vector<Card>& v, int left, int mid, int right) {
    vector<Card> l(mid - left + 1);
    for (int i = 0; i < l.size() - 1; ++i)
        l[i] = v[i + left];
    vector<Card> r(right - mid + 1);
    for (int i = 0; i < r.size() - 1; ++i)
        r[i] = v[i + mid];

    l[l.size() - 1].n = INT_MAX;
    r[r.size() - 1].n = INT_MAX;

    int idx_left = 0;
    int idx_right = 0;
    int compare_count = 0;
    for (int i = left; i < right; ++i) {
        if (l[idx_left].n <= r[idx_right].n) {
            v[i] = l[idx_left];
            ++idx_left;
        } else {
            v[i] = r[idx_right];
            ++idx_right;
        }
        ++compare_count;
    }

    return compare_count;
}

// sort v[left] to v[right-1] with merge sort algorithm
// v[right] will not be modified
int _merge_sort(vector<Card>& v, int left, int right) {
    int count = 0;

    if (left + 1 < right) {
        int mid = left + (right - left) / 2;
        count += _merge_sort(v, left, mid);
        count += _merge_sort(v, mid, right);
        count += merge(v, left, mid, right);
    }

    return count;
}

int merge_sort(vector<Card>& v) { return _merge_sort(v, 0, v.size()); }

int partition(vector<Card>& v, int left, int right) {
    int base = v[right].n;
    int idx = left - 1;
    for (int i = left; i < right; ++i) {
        if (v[i].n <= base) {
            ++idx;
            swap(v[idx], v[i]);
        }
    }
    ++idx;
    swap(v[idx], v[right]);
    return idx;
}

void _quick_sort(vector<Card>& v, int left, int right) {
    if (left < right) {
        int idx = partition(v, left, right);
        _quick_sort(v, left, idx - 1);
        _quick_sort(v, idx + 1, right);
    }
}

void quick_sort(vector<Card>& v) { _quick_sort(v, 0, v.size() - 1); }

int main() {
    int n;
    cin >> n;

    vector<Card> cards(n);
    vector<Card> cards_stable(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i].c >> cards[i].n;
        cards_stable[i].c = cards[i].c;
        cards_stable[i].n = cards[i].n;
    }

    quick_sort(cards);
    merge_sort(cards_stable);

    bool stable = true;
    for (int i = 0; i < n; ++i) {
        if (cards[i].c != cards_stable[i].c ||
            cards[i].n != cards_stable[i].n) {
            stable = false;
            break;
        }
    }
    if (stable)
        cout << "Stable\n";
    else
        cout << "Not stable\n";

    for (int i = 0; i < n; ++i)
        cout << cards[i].c << ' ' << cards[i].n << '\n';
}


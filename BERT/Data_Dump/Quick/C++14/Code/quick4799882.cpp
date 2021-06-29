#include <bits/stdc++.h>
#define fastIO (ios::sync_with_stdio(false), cin.tie(0), cout.tie(0))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define SENTINEL 1000000001
using ui = uint64_t;
using li = int64_t;
using namespace std;

struct Card {
    int num;
    char mark;
};

int partition(vector<Card> &a, int p, int r) {
    auto swap = [&](auto &a, int i, int j) {
        Card temp = a.at(i);
        a.at(i) = a.at(j);
        a.at(j) = temp;
    };

    int pivot = a.at(r).num;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a.at(j).num <= pivot) {
            i = i + 1;
            swap(a, i, j);
        }
    }

    swap(a, i + 1, r);
    return i + 1;
}

void quickSort(vector<Card> &A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

bool compare(Card a, Card b) {
    return a.num == b.num && a.mark == b.mark;
};

int main() {
    fastIO;

    int n;
    cin >> n;

    vector<Card> deck1, deck2;

    rep(i, n) {
        char mark;
        int num;
        cin >> mark >> num;

        Card c = {num, mark};
        deck1.push_back(c);
        deck2.push_back(c);
    }

    quickSort(deck2, 0, deck2.size() - 1);
    stable_sort(deck1.begin(), deck1.end(),
                [](Card a, Card b) { return a.num < b.num; });

    bool is_stable{true};

    rep(i, n) {
        if (!compare(deck1.at(i), deck2.at(i)))
            is_stable = false;
    }

    cout << (is_stable ? "Stable" : "Not stable") << endl;
    for (auto card : deck2) {
        cout << card.mark << " " << card.num << endl;
    }
}


// クイックソート
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

#define INF 1e9 + 1

struct Card {
    char mark;
    int num;
};

void merge(Card* a, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    Card L[n1 + 1];
    Card R[n2 + 1];
    Card c; c.num = INF;
    rep(i, n1) L[i] = a[left + i];
    rep(i, n2) R[i] = a[mid + i];
    L[n1] = R[n2] = c;
    int lc = 0; int rc = 0;
    for (int i = left; i < right; i += 1) {
        if (L[lc].num <= R[rc].num) {
            a[i] = L[lc++];
        } else {
            a[i] = R[rc++];
        }
    }
}

void mergeSort(Card* a, int left, int right) {
    if (left + 1 >= right) return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
}

void swap(Card* a, int idx1, int idx2) {
    Card tmp = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = tmp;
}

int partition(Card* a, int p, int r) {
    Card x = a[r];
    int i = p;
    for (int j = p; j < r; j += 1) {
        if (a[j].num <= x.num) swap(a, i++, j);
    }
    swap(a, i, r);
    return i;
}

void quicksort(Card* a, int p, int r) {
    if (p >= r) return;
    int q = partition(a, p, r);
    quicksort(a, p, q - 1);
    quicksort(a, q + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    Card cards[n];
    Card bu[n];
    rep(i, n) {
        scanf("%s %d", &cards[i].mark, &cards[i].num);
        bu[i] = cards[i];
    }
    quicksort(cards, 0, n - 1);
    mergeSort(bu, 0, n);
    bool f = true;
    rep(i, n) {
        if (cards[i].mark != bu[i].mark || cards[i].num != bu[i].num) {
            f = false;
        }
    }
    if (f) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
    rep(i, n) {
        printf("%c %d\n", cards[i].mark, cards[i].num);
    }
    return 0;
}

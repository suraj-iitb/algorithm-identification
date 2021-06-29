#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
const double PI = 3.141592653589793;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

struct Card{
    char suit;
    int value;
};

bool isEqual(Card C1[], Card C2[], int N) {
    rep(i, N) {
        if(C1[i].suit != C2[i].suit) return false;
    }
    return true;
}

int partition(Card C[], int p, int r) {
    int x = C[r].value, i = p - 1;
    for (int j = p; j < r; j++){
        if (C[j].value <= x) swap(C[++i], C[j]);
    }
    swap(C[i + 1], C[r]);
    return ++i;
}

void quickSort(Card C[], int p, int r) {
    if (p >= r) return;
    int q = partition(C, p, r);
    quickSort(C, p, q - 1);
    quickSort(C, q + 1, r);
}

void merge(Card C[], int left, int mid, int right){
    int n1 = mid - left, n2 = right - mid;
    Card L[n1 + 1], R[n2 + 1];
    rep(i, n1) L[i] = C[left + i];
    rep(i, n2) R[i] = C[mid + i];
    L[n1].value = INF;
    R[n2].value = INF;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) C[k] = L[i++];
        else C[k] = R[j++];
    }
}

void mergeSort(Card C[], int left, int right) {
    if (right - left == 1) return;
    int mid = (left + right) / 2;
    mergeSort(C, left, mid);
    mergeSort(C, mid, right);
    merge(C, left, mid, right);
}

int n;
Card C1[110000], C2[110000];

int main() {
    cin >> n;
    rep(i, n) cin >> C1[i].suit >> C1[i].value;
    rep(i, n) C2[i] = C1[i];
    quickSort(C1, 0, n - 1);
    mergeSort(C2, 0, n);
    cout << ((isEqual(C1, C2, n))? "Stable" : "Not stable") << endl;
    rep(i, n) cout << C1[i].suit << " " << C1[i].value << endl;
}


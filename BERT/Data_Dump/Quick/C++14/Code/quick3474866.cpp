#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define rep(i, N) for(int i = 0; i < N; ++i)

using namespace std;
struct card {char suit; int value;};
int N;
const int SENTINEL = 1LL << 29;
const int MAX = 100100;
card A[MAX];
card B[MAX];
struct card L[MAX/2 + 2], R[MAX/2 + 2];

int partition(int p, int r) {
    int x = A[r].value;
    int i = p-1;
    for(int j = p; j < r; ++j) {
        if (A[j].value <= x) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
   return i+1;
}

void quickSort(int p, int r) {
    if (p < r) {
        int q = partition(p, r);
        quickSort(p, q-1);
        quickSort(q+1, r);
    }
}

void merge(int n, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i, n1) L[i] = B[left + i];
    rep(i, n2) R[i] = B[mid + i];
    L[n1].value = R[n2].value = SENTINEL;
    i = j = 0;
    for(k = left; k < right; ++k) {
        if (L[i].value <= R[j].value) B[k] = L[i++];
        else B[k] = R[j++];
    }
}

void mergeSort(int n, int left, int right) {
    int mid;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        mergeSort(n, left, mid);
        mergeSort(n, mid, right);
        merge(n, left, mid, right);
    }
}

int main() {
    cin >> N;
    rep(i, N) {
        char s; cin >> s;
        int v; cin >> v;
        A[i].suit = B[i].suit = s; 
        A[i].value = B[i].value = v;
    }
    mergeSort(N, 0, N);
    quickSort(0, N-1);
    string isStable = "Stable";
    rep(i, N) if(A[i].suit != B[i].suit) isStable = "Not stable";
    cout << isStable << endl;
    rep(i, N) cout << A[i].suit << " " << A[i].value << endl;


}


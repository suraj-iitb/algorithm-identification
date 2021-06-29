#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define rep(i, N) for(int i = 0; i < N; ++i)

using namespace std;

const int INF = 2000000000;

int n;
int S[500100];
int res = 0;
int L[500000];
int R[500000];

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i, n1) L[i] = A[left+i];
    rep(i, n2) R[i] = A[mid+i];
    L[n1] = R[n2] = INF;

    int i = 0; int j = 0;
    for (int k = left; k < right; ++k) {
        if(L[i] <= R[j]) A[k] = L[i++];
        else A[k] = R[j++];
        ++res;
    }

}

void mergeSort(int A[], int left, int right) {
    if (left < right -1) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
int main() {
    cin >> n;
    rep(i, n) cin >> S[i];
    mergeSort(S, 0, n);
    rep(i, n) {
        if(i > 0) cout << " ";
        cout << S[i];
    }
    cout << endl << res << endl;
}


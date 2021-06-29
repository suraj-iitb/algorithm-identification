#include <iostream>
#include <vector>
using namespace std;

static const int INF = 1000000000;
int cnt = 0;

void merge(vector<int> &A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1 + 1), R(n2 + 1);
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = INF, R[n2] = INF;

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void merge_sort(vector<int> &A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];

    merge_sort(S, 0, n);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << S[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

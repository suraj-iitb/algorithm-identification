#include <bits/stdc++.h>
using namespace std;

#define INF 1000000001
#define N_MAX 500005

int S[N_MAX];
int cnt;

void merge(int S[], int left, int mid, int right) {
    int n_left = mid - left;
    int n_right = right - mid;

    int L[N_MAX/2+2], R[N_MAX/2+2];
    for (int i = 0; i < n_left; i++) {
        L[i] = S[left + i];
    }
    for (int i = 0; i < n_right; i++) {
        R[i] = S[mid + i];
    }
    L[n_left] = INF;
    R[n_right] = INF;

    int idx_L = 0;
    int idx_R = 0;

    for (int k = left; k < right; k++) {
        cnt++;
        if (L[idx_L] <= R[idx_R]) {
            S[k] = L[idx_L];
            idx_L++;
        }
        else {
            S[k] = R[idx_R];
            idx_R++;
        }
    }

    // while (L[idx_L] != INF || R[idx_R] != INF) {
    //     if (L[idx_L] <= R[idx_R]) {
    //         S[left + idx_L + idx_R] = L[idx_L];
    //         idx_L++;
    //     }
    //     else {
    //         S[left + idx_L + idx_R] = R[idx_R];
    //         idx_R++;
    //     }
    // }

}

void mergeSort(int S[], int left, int right) {
    if (right - left > 1) {
        int mid = (left + right) / 2;
        mergeSort(S, left, mid);
        mergeSort(S, mid, right);
        merge(S, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    cnt = 0;
    int left = 0;
    int right = n;
    mergeSort(S, left, right);

    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << S[i];
    }
    cout << endl;
    cout << cnt << endl;
}


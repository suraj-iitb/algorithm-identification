#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int64_t cnt = 0;
void merge(vector<int64_t>& S, int64_t left, int64_t mid, int64_t right) {
    int64_t n1 = mid - left;
    int64_t n2 = right - mid;
    vector<int64_t>L(n1+1);
    vector<int64_t>R(n2+1);
    for (int i=0; i < n1; i++) {
        L.at(i) = S[left + i];
    }

    for (int i=0; i < n2; i++) {
        R.at(i) = S[mid + i];
    }

    L[n1] = INT64_MAX;
    R[n2] = INT64_MAX;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        cnt += 1;
        if (L[i] <= R[j]) {
            S[k] = L[i];
            i+= 1;
        } else {
            S[k] = R[j];
            j += 1;
        }
    }

}

void mergeSort(vector<int64_t>& S, int64_t left, int64_t right) {
    if (left + 1 < right) {
        int64_t mid = (left + right) / 2;
        mergeSort(S, left, mid);
        mergeSort(S, mid, right);
        merge(S, left, mid, right);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int64_t>vec(N);
    for (int i=0; i < N; i++) {
        cin >> vec.at(i);
    }

    mergeSort(vec, 0, N);
    for (int i=0; i < N; i++) {
        if (i) {
            cout << " ";
        }
        cout << vec[i];
    }
    cout << endl;

    cout << cnt << endl;

    return 0;
}

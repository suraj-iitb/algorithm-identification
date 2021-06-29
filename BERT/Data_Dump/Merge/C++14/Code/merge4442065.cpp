#include <bits/stdc++.h>
using namespace std;

#define SENTINEL 2000000000

int cnt = 0;

void merge(vector<int> &A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1+1);
    vector<int> R(n2+1);

    for (int i = 0; i < n1; i++) {
        L.at(i) = A.at(left + i);
    }
    for (int i = 0; i < n2; i++) {
        R.at(i) = A.at(mid + i);
    }
    L.at(n1) = SENTINEL;
    R.at(n2) = SENTINEL;

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L.at(i) > R.at(j)) {
            A.at(k) = R.at(j);
            j++;
        }
        else {
            A.at(k) = L.at(i);
            i++;
        }
    }
}

void mergesort(vector<int> &A, int left, int right) {
    if (left+1 < right) {
        int mid = (left + right) / 2;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> A;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    mergesort(A, 0, N);

    for (int i = 0; i < N; i++) {
        if (i)
            cout << " ";
        cout << A.at(i);
    }
    cout << endl;
    cout << cnt << endl;
}


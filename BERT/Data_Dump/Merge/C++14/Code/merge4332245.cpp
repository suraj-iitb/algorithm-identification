#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &S, int left, int mid, int right, int &count) {
    int n1, n2;
    n1 = mid - left;
    n2 = right - mid;
    vector<int> L(n1 + 1), R(n2 + 1);
    for (int i = 0; i < n1; i++) {
        L.at(i) = S.at(left + i);
    }
    for (int i = 0; i < n2; i++) {
        R.at(i) = S.at(mid + i);
    }
    L.at(n1) = 1000000001;
    R.at(n2) = 1000000001;
    
    int i, j;
    i = 0;
    j = 0;
    for (int k = left; k < right; k++) {
        count++;
        if (L.at(i) <= R.at(j)) {
            S.at(k) = L.at(i);
            i++;
        } else {
            S.at(k) = R.at(j);
            j++;
        }
    }
}

void mergeSort(vector<int> &S, int left, int right, int &count) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(S, left, mid, count);
        mergeSort(S, mid, right, count);
        merge(S, left, mid, right, count);
    }
}

void mergeSort(vector<int> &S, int &count) {
    mergeSort(S, 0, S.size(), count);
}

int main() {
    int n, count;
    cin >> n;
    count = 0;
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S.at(i));
    }

    mergeSort(S, count);

    for (int i = 0; i < n - 1; i++) {
        printf("%d ", S.at(i));
    }
    cout << S.at(n - 1) << endl;
    cout << count << endl;
}

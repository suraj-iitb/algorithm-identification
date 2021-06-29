#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define SENTINEL 2000000000

vector< pair<string, int> > L(MAX/2+2), R(MAX/2+2);

void merge(vector< pair<string, int> > &A, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L.at(i) = A.at(left + i);
    for (int i = 0; i < n2; i++) R.at(i) = A.at(mid + i);
    L.at(n1).second = R.at(n2).second = SENTINEL;
    i = j = 0;
    for (k = left; k < right; k++) {
        if (L.at(i).second <= R.at(j).second) {
            A.at(k) = L.at(i++);
        } else {
            A.at(k) = R.at(j++);
        }
    }
}

void mergeSort(vector< pair<string, int> > &A, int left, int right) {
    int mid;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(vector< pair<string, int> > &A, int p, int r) {
    int x = A.at(r).second;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A.at(j).second <= x) {
            i = i + 1;
            swap(A.at(i), A.at(j));
        }
    }
    swap(A.at(i+1), A.at(r));
    return i + 1;
}

void quickSort(vector< pair<string, int> > &A, int p, int r) {
    int q;
    if (p < r) {
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector< pair<string, int> > A(n);
    vector< pair<string, int> > B(n);
    for (int i = 0; i < n; i++) {
        string f;
        int s;
        cin >> f >> s;
        A.at(i) = make_pair(f, s);
        B.at(i) = make_pair(f, s);
    }

    mergeSort(A, 0, n);
    quickSort(B, 0, n-1);

    bool stable = true;
    for (int i =0; i < n; i++) {
        if (A.at(i).first != B.at(i).first) stable = false;
    }
    if (stable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    for (int i = 0; i < n; i++) {
        cout << B.at(i).first << " " << B.at(i).second << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <climits>

using namespace std;

int c = 0;

void merge(deque<int>& A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    // L[0...n1], R[0...n2] を生成
    deque<int> L;
    deque<int> R;
    for (int i = 0; i < n1; ++i) {
        L.push_back(A[left + i]);
    }
    for (int i = 0; i < n2; ++i) {
        R.push_back(A[mid + i]);

    }
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    int i = 0;
    int j = 0;
    for (int k = left; k < right; ++k) {
        ++c;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        }
        else {
            A[k] = R[j];
            ++j;
        }

    }
}

    void mergeSort(deque<int>& A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    deque<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    mergeSort(a, 0, n);
    cout << a[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << a[i];
    }
    cout << endl << c << endl;

    return 0;
}


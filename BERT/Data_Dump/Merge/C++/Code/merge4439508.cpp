#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int A[500001];
int cnt = 0;

void merge(int left, int mid, int right) {
    vector<int> v1;

    cnt += right - left + 1;
    int p1 = left;
    int p2 = mid + 1;

    while (p1 <= mid && p2 <= right) {
        if (A[p1] < A[p2]) {
            v1.push_back(A[p1]);
            p1++;
        } else {
            v1.push_back(A[p2]);
            p2++;
        }
    }

    while (p1 <= mid) {
        v1.push_back(A[p1]);
        p1++;
    }

    while (p2 <= right) {
        v1.push_back(A[p2]);
        p2++;
    }

    for (int i = 0; i < v1.size(); ++i) {
        A[left + i] = v1[i];
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + ((right - left) >> 1);
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cout << A[i];
        } else {
            cout << " " << A[i];
        }
    }
    cout << endl;
    cout << cnt << endl;
}


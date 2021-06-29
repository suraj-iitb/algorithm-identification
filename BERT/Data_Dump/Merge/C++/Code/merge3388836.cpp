#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

void merge(vector<int>& A, int left, int mid, int right) {
    vector<int> v1(A.begin() + left, A.begin() + mid), v2(A.begin() + mid, A.begin() + right);
    int i = 0, j = 0, k = left;
    while (i < v1.size() && j < v2.size()) {
        cnt++;
        if (v1[i] <= v2[j]) {
            A[k++] = v1[i++];
        } else {
            A[k++] = v2[j++];
        }
    }
    while (i < v1.size()) {
        cnt++;
        A[k++] = v1[i++];
    }
    while (j < v2.size()) {
        cnt++;
        A[k++] = v2[j++];
    }
}

void merge_sort(vector<int>& A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    //freopen("ALDS1_5_B_Merge_Sort_Data.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    merge_sort(A, 0, n);

    for (int i = 0; i < n; i++) {
        if (i) cout << " " ;
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}

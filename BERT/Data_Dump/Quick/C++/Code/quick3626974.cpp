#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

struct card {
    char suit;
    int value;
};

//マージソート用関数 merge, mergesort
void merge(card A[], int left, int mid, int right) {
    card L[50001], R[50001];
    int n1 = mid - left;
    int n2 = right - mid;
    
    for (int i = 0; i < n1 + 1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + 1 + i];

    L[n1 + 1].value = INFINITY;
    R[n2].value = INFINITY;

    int li = 0, rj = 0;
    for (int ak = left; ak < right + 1; ak++ ) {
        if (L[li].value <= R[rj].value) {
            A[ak] = L[li];
            li++;
        } else {
            A[ak] = R[rj];
            rj++;
        }
    }
}

void mergeSort(card A[], int left, int right) {
    if (left == right) return;

    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
}

// クイックソート用関数 parttion, quickSort
int partition(card A[], int p, int r) {
    int base = A[r].value;

    int separator_idx = p-1;
    int exp_idx = p;

    for(; exp_idx <= r ; exp_idx++) {
        if(A[exp_idx].value <= base) {
            separator_idx++;
            swap(A[exp_idx], A[separator_idx]);
        }
    }
    return separator_idx;
}

void quickSort(card A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main(void) {
    int n;
    cin >> n;
    card A[100000], B[100000];
    bool stable = true;

    for (int i = 0; i < n; i++) {
        cin >> A[i].suit >> A[i].value;
        B[i] = A[i];
    }

    mergeSort(A, 0, n-1);
    quickSort(B, 0, n-1);

    for (int i = 0; i < n; i++) {
        if ( A[i].suit != B[i].suit ) stable = false;
    }

    if (stable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    for (int i = 0; i < n; i++) {
        cout << B[i].suit << " " << B[i].value << endl;
    }

    return 0;
}

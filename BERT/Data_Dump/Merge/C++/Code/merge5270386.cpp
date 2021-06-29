#include <iostream>
using namespace std;
#define MAX 500000
#define INF 1000000001
int n, S[MAX], sum = 0;

void merge(int left, int right) {
    int mid = (left + right) / 2;
    int left_len = mid - left;
    int right_len = right - mid;
    int L[left_len+1], R[right_len+1];
    for ( int i = 0; i < left_len; i++ ) L[i] = S[left+i];
    for ( int i = 0; i < right_len; i++ ) R[i] = S[mid+i];
    L[left_len] = INF, R[right_len] = INF;
    int i = 0, j = 0;
    for ( int k = left; k < right; k++ ) {
        if ( L[i] <= R[j] ) {
            S[k] = L[i];
            i++;
        }
        else {
            S[k] = R[j];
            j++;
        }
        sum++;
    }
}

void merge_sort(int left, int right) {
    int mid = (left + right) / 2;
    int len = right - left;
    if ( len <= 1 ) return;
    // left side divide operation
    merge_sort(left, mid);
    // right side divide operation
    merge_sort(mid, right);
    // merge operation
    merge(left, right);
}

int main() {
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> S[i];
    merge_sort(0, n);
    for (int i = 0; i < n; i++) {
        cout << S[i];
        i != n-1 ? cout << " " : cout << endl;
    }
    cout << sum << endl;

    return 0;
}


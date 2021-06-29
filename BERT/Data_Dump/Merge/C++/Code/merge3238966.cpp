#include <iostream>

using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt;

void merge(int S[], int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    
    for (int i = 0; i < n1; i++) {
        L[i] = S[left + i];
    }
    
    for (int i = 0; i < n2; i++) {
        R[i] = S[mid + i];
    }
    
    L[n1] = R[n2] = SENTINEL;
    
    int i = 0, j = 0;
    
    for (int k = left; k < right; k++) {
        cnt++;
        
        if (L[i] <= R[j]) {
            S[k] = L[i++];
        } else {
            S[k] = R[j++];
        }
    }
}

void mergeSort(int S[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(S, n, left, mid);
        mergeSort(S, n, mid, right);
        merge(S, n, left, mid, right);
    }
}

int main() {
    int n, S[MAX];
    int i;
    cnt = 0;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> S[i];
    }
    
    mergeSort(S, n, 0, n);
    
    for (i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << S[i];
    }
    
    cout << endl;
    
    cout << cnt << endl;
    
    return 0;
}


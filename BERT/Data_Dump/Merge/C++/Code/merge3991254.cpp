#include <iostream>
using namespace std;

const int MAX_N = 500000;
int ans = 0;
const int INF = 2100000000;


void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[MAX_N], R[MAX_N];
    
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    
    L[n1] = INF;
    R[n2] = INF;
    
    int l = 0;
    int r = 0;
    for (int i = left; i < right; i++) {
        if (L[l] <= R[r]) {
            A[i] = L[l];
            l++;
        } else {
            A[i] = R[r];
            r++;
        }
        ans++;
    }
}

void merge_sort(int A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void){
    // Your code here!
    int N;
    int S[MAX_N];
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    
    merge_sort(S, 0, N);
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << S[i];
    }
    cout << endl << ans << endl;
    return 0;
}


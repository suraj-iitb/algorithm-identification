#include<iostream>
 
using namespace std;
 
#define MAX 500000
#define INFTY 2000000000
 
int L[MAX / 2 + 2], R[MAX / 2 + 2], count;
 
void marge (int A[], int n, int left, int mid, int right) {
 
    int n1 = mid -left, n2 = right - mid;
    int i, j, k;
 
    for (i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
 
    for (i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
 
    L[n1] = INFTY;
    R[n2] = INFTY;
 
    i = 0;
    j = 0;
 
    for (k = left; k < right; k++) {
 
        count++;
 
        if (L[i] <= R[j]) {
 
            A[k] = L[i];
            i++;
 
        } else {
 
            A[k] = R[j];
            j++;
 
        }
 
    }
 
}
 
void margeSort (int A[], int n, int left, int right) {
 
    int mid;
 
    if (left + 1 < right) {
 
        mid = (left + right) / 2;
 
        margeSort (A, n, left, mid);
        margeSort (A, n, mid, right);
 
        marge (A, n, left, mid, right);
 
    }
 
}
 
int main () {
 
    int A[MAX], n, i;
    count = 0;
 
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> A[i];
    }
 
    margeSort (A, n, 0, n);
 
    for (i = 0; i < n; i++) {
 
        if (i) {
            cout << " ";
        }
 
        cout << A[i];
 
    }
 
    cout << endl;
 
    cout << count << endl;
 
    return 0;
 
}

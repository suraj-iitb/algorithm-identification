#include <iostream>
#include <limits>
using namespace std;

int A[100000000], n, cnt, i;
int inf = 2000000000;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i=0; i<n1; i++){
        L[i] = A[left + i];
    }
    for (i=0; i<n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = inf;
    R[n2] = inf;
    int i=0, j=0;
    for (int k=left; k<right; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            cnt += 1;
            i = i + 1;
        }
        else{
            A[k] = R[j];
            cnt += 1;
            j = j + 1;
        }
    }
}

void mergesort(int A[], int left, int right){
    if (left+1 < right){
        int mid = (left + right)/2;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    cin >> n;
    int S[n];
    for (int i=0; i<n; i++){
        cin >> S[i];
    }
    int left = 0, right = n;
    mergesort(S, left, right);
    for (int i=0; i<n; i++) {
        if (i != n-1) cout << S[i] << " ";
        else cout << S[i] << "\n"; 
    }
    cout << cnt << "\n";

    return 0;
}

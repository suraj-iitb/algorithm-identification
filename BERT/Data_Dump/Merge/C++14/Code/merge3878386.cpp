#include <iostream>
#define rep(i,n) for (int i = 0; i < (n); ++i) 
#define MAX 500000
#define SENTINEL 2000000000
typedef long long ll;
using namespace std;

int L[MAX/2+5], R[MAX/2+5];
int cnt;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i,n1) L[i] = A[left+i];
    rep(i,n2) R[i] = A[mid+i];

    L[n1] = R[n2] = SENTINEL;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; ++k){
        ++cnt;
        if(L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        } 
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left + 1 < right){
        int mid = (left + right) /2;

        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int n, A[MAX];
    cnt = 0;

    cin >> n;
    rep(i, n) cin >> A[i];

    mergeSort(A, 0, n);

    rep(i,n){
        if(i > 0) cout << " ";
        cout << A[i];
    }

    cout << endl;

    cout << cnt << endl;

    return 0;
}

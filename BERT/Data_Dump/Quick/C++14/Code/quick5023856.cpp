#include <iostream>
#include <limits>
using namespace std;

int i, inf = 2000000000;

struct Card{
    char mrk;
    int num;
};


void merge(Card A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    Card L[n1+1], R[n2+1];
    for (i=0; i<n1; i++){
        L[i] = A[left + i];
    }
    for (i=0; i<n2; i++){
        R[i] = A[mid + i];
    }
    L[n1].num = inf;
    R[n2].num = inf;
    int i=0, j=0;
    for (int k=left; k<right; k++){
        if (L[i].num <= R[j].num){
            A[k] = L[i];
            i = i + 1;
        }
        else{
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void mergesort(Card A[], int left, int right){
    if (left+1 < right){
        int mid = (left + right)/2;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(Card A[], int p, int r)
{
    Card x, y;
    int i, j;
    x = A[r];
    i = p-1;
    for (j=p; j<r; j++){
        if (A[j].num <= x.num){
            i += 1;
            y = A[i];
            A[i] = A[j];
            A[j] = y;
        }
    }
    y = A[i+1];
    A[i+1] = A[r];
    A[r] = y;

    return i+1;
}

void quicksort(Card A[], int p, int r)
{
    if (p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int main()
{
    int n, p, r, i, stable=1;
    cin >> n;
    Card A[n], B[n];
    p = 0;
    r = n-1;

    for (i=0; i<n; i++){
        cin >> A[i].mrk >> A[i].num;
        B[i] = A[i];
    }

    mergesort(B, p, r+1);
    quicksort(A, p, r);

    for (i=0; i<n; i++){
        if (A[i].mrk != B[i].mrk) stable = 0;
    }
    if (stable == 0) cout << "Not stable" << "\n";
    else cout << "Stable" << "\n";

    for (i=0; i<n; i++){
        cout << A[i].mrk << " " << A[i].num << "\n";
    }
    
    return 0;
}

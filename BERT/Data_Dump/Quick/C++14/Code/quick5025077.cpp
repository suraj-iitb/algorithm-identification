#include<iostream>
using namespace std;

//quickSort

#define MAX 100000
#define SENTINEL 2000000000

struct Card{
    char suit;
    int value;
};

struct Card L[MAX / 2 + 2], R[MAX/ 2 + 2];

void marge(struct Card A[], int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++) L[i] = A[left + i];
    for(int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1].value = R[n2].value = SENTINEL;
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        if(L[i].value <= R[j].value) A[k] = L[i++];
        else A[k] = R[j++];
    }
}

void margeSort(struct Card A[], int n, int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        margeSort(A, n, left, mid);
        margeSort(A, n, mid, right);
        marge(A, n, left, mid, right);
    }
}

int partition(struct Card A[], int n, int p, int r){
    int i, j;
    struct Card tmp, x;
    x = A[r];
    i = p - 1;
    for(j = p; j < r; j++){
        if(A[j].value <= x.value){
            i = i + 1;
            tmp = A[i], A[i] = A[j], A[j] = tmp;
        }
    }
    tmp = A[i+1], A[i+1] = A[r], A[r] = tmp;
    return i + 1;
}

void quickSort(struct Card A[], int n, int p, int r){
    int q;
    if(p < r){
        q = partition(A, n, p, r);
        quickSort(A, n, p, q-1);
        quickSort(A, n, q+1, r);
    }
}

int main(){
    int n, v, stable = 1;
    struct Card A[MAX], B[MAX];
    char S[10];

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> S >> v;
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }

    margeSort(A, n, 0, n);
    quickSort(B, n, 0, n-1);

    for(int i = 0; i < n; i++){
        if(A[i].suit != B[i].suit) stable = 0;
    }

    if(stable == 1) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    for(int i = 0; i < n; i++){
        cout << B[i].suit << ' ' << B[i].value << endl;
    }

    return 0;
}

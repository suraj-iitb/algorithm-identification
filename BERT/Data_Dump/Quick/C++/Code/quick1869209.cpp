#include<iostream>
#define MAX 100000
#define SENTINEL 2000000000
using namespace std;

struct Card 
{
    char suit;
    int value;
};

struct Card L[MAX / 2+2],R[MAX / 2+2];

void merge(Card A[], int n, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++){
        L[i] = A[left+i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = A[mid+i];
    }
    L[n1].value = SENTINEL;
    R[n2].value = SENTINEL;

    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++){
        if (L[i].value <= R[j].value){
            A[k] = L[i];
            i += 1;
        } else {
            A[k] = R[j];
            j += 1;
        }
        
    }
    
    
    
}

void mergeSort(Card A[], int n, int left, int right)
{
    if (left + 1 < right){
        int mid = (right + left) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
        
    }
    
}

    

int partition(Card A[], int p, int r)
{
    struct Card t, x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++){
        if (A[j].value <= x.value){
            i += 1;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;

    return i+1;
    
    
}

void quickSort(Card A[], int p, int r)
{
    if(p < r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
        
    }
    
}

int main()
{
    int n, v;
    struct Card A[MAX], B[MAX];
    char S[10];
    int stable = 1;
    
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> S >> v;
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }
    mergeSort(B, n, 0, n);
    quickSort(A, 0, n-1);
    for (int i = 0; i < n; i++){
        if (A[i].suit != B[i].suit) {
            stable = 0;
        }
        
    }
    
    if (stable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    
    for (int i = 0; i < n; i++){

        cout << A[i].suit << " " << A[i].value << endl;

    }
    
    return 0;
}

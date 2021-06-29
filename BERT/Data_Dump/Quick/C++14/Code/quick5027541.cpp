#include<iostream>
#include<utility>
#define MAX 100000
#define SENTINEL 2000000000
using namespace std;

struct Card{
    char suit;
    int value;
};

struct Card L[MAX/2+2], R[MAX/2+2];

void merge(int n, struct Card A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0; i<n1; i++) L[i] = A[left+i];
    for(int i=0; i<n2; i++) R[i] = A[mid+i];
    L[n1].value = SENTINEL;
    R[n2].value = SENTINEL;
    int i = 0;
    int j = 0;
    for(int k=left; k<right; k++){
        if(L[i].value<=R[j].value){
            A[k] = L[i];
            i = i + 1;
        }
        else{
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void mergeSort(int n, struct Card A[], int left, int right){
    if(left+1<right){
        int mid = (left + right) / 2;
        mergeSort(n, A, left, mid);
        mergeSort(n, A, mid, right);
        merge(n, A, left, mid, right);
    }
}
int partition(int n, struct Card A[], int p, int r){
    int i, j;
    struct Card x;
    x = A[r];
    i = p-1;
    for(j=p; j<r; j++){
        if(A[j].value<=x.value){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quickSort(int n, struct Card A[], int p, int r){
    int q;
    if(p<r){
        q = partition(n, A, p, r);
        quickSort(n, A, p, q-1);
        quickSort(n, A, q+1, r);
    }
}

int main(){
    int n, i, v;
    struct Card A[MAX], B[MAX];
    char S[10];
    int stable = 1;

    cin >> n;
    for(i=0; i<n; i++){
        cin >> S >> v;;
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }
    
    mergeSort(n, A, 0, n);
    quickSort(n, B, 0, n-1);

    for(i=0; i<n; i++){
        if(A[i].suit != B[i].suit) stable = 0;
    }

    if(stable==1) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    for(i=0; i<n; i++) cout << B[i].suit << " " << B[i].value << endl;
    return 0;
}

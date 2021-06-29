#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;

int L[500001], R[500001];
char LSuits[500001], RSuits[500001];

void merge(int *A, char *suits, int left, int mid, int right){
    int i;
    int n = mid - left + 1;
    int n2 = right - mid;
    for(i=0;i<n;i++) {
        L[i] = A[left+i];
        LSuits[i] = suits[left+i];
    }
    for(i=0;i<n2;i++) {
        R[i] = A[mid+i+1];
        RSuits[i] = suits[mid+i+1];
    }
    L[n] = R[n2] = INT_MAX;
    int r=0, l=0;
    for(i=left;i<=right;i++){
        if(L[l] <= R[r]){
            A[i] = L[l++];
            suits[i] = LSuits[l-1];
        }else{
            A[i] = R[r++];
            suits[i] = RSuits[r-1];
        }
    }
}

void mergeSort(int *A, char *suits, int left, int right){
    if(left<right){
        int mid = (left + right) / 2;
        mergeSort(A, suits, left, mid);
        mergeSort(A, suits, mid+1, right);
        merge(A, suits, left, mid, right);
    }
}

int partition(int *A, char *suits, int p, int r){
    int i, pos = p-1;
    int rep = A[r];
    for(i=p;i<r;i++){
        if(A[i] <= rep){
            swap(A[++pos], A[i]);
            swap(suits[pos], suits[i]);
        }
    }
    swap(A[r], A[++pos]);
    swap(suits[r], suits[pos]);
    return pos;
}

void quicksort(int *A, char *suits, int p, int r){
    if (p<r){
        int q = partition(A, suits, p, r);
        quicksort(A, suits, p, q-1);
        quicksort(A, suits, q+1, r);
    }
    return;
}

void compairSuits(char *s1, char *s2, int n){
    rep(i,n){
        if(s1[i]!=s2[i]){
            cout << "Not stable" << endl;
            return;
        }    
    }
    cout << "Stable" << endl;
}

int main(){
    int n;
    cin>>n;

    int i, A[n], A2[n];
    char suits[n], suits2[n];
    for(i=0;i<n;i++){
        cin>>suits[i];
        suits2[i] = suits[i];
        cin>>A[i];
        A2[i] = A[i];
    }

    quicksort(A, suits, 0, n-1);
    mergeSort(A2, suits2, 0, n-1);

    compairSuits(suits, suits2, n);

    rep(i,n){
        cout << suits[i]  << " "<< A[i] << endl;
    }

    return 0;
}



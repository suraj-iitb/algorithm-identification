#include <iostream>
#include <vector>
#include <utility>


using namespace std;

#define MAX 200000
#define SENTINEL 200000000

pair<char,int> L[MAX/2+2], R[MAX/2+2];

void merge(pair<char,int> A[], int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0; i<n1;++i) L[i] = A[left+i];
    for(int i=0; i<n2;++i) R[i] = A[mid+i];
    L[n1].second = R[n2].second = SENTINEL;

    int i = 0, j = 0;
    for(int k=left;k<right;++k){
        if(L[i].second <= R[j].second) A[k] = L[i++];
        else
        {
            A[k] = R[j++];
        }
        
    }

}

void mergeSort(pair<char,int> A[], int n, int left, int right){
    if(left+1<right){
        int mid = (left+right)/2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}


void swap(pair<char,int> *a, pair<char, int> *b){
    pair<char,int> temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(pair<char,int> A[], int p, int r){
    int x = A[r].second;
    int i = p-1;
    for(int j=p;j<r;++j){
        if(A[j].second <= x){
            ++i;
            swap(&(A[i]),&(A[j]));
        }
    }
    swap(&(A[i+1]), &(A[r]));
    return i+1;
}

void quickSort(pair<char,int> A[], int p, int r){
    int q;
    if(p < r){
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}


int main(){
    int n;
    cin >> n;
    pair<char,int> A[n], B[n];
    int v;
    char c;
    for(int i=0;i<n;++i){
         cin >> c >> v;
         A[i].first = B[i].first = c;
         A[i].second = B[i].second = v;
    }

    quickSort(A,0, n-1);
    mergeSort(B, n, 0, n);

    bool stable=true;

    for(int i=0; i< n; ++i){
        if(A[i].first != B[i].first) stable = false;
    }
    

    if(stable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    for(int i=0; i<n; ++i) cout << A[i].first << " " << A[i].second << endl;
    

    return 0;

}

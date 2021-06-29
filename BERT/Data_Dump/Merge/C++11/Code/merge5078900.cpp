#include <iostream>

using namespace std;

int c = 0, L[300000], R[300000];

void merge(int A[], int l, int mid, int r){
    int n1, n2, i, j;
    //cout << "l: " << l << "  r: " << r<< endl;
    n1 = mid - l;
    n2 = r - mid;
    for(int d = 0; d < n1; d++){
        L[d] = A[l + d];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid + i];
        //cout << "L: " <<  L[i] << " R: " << R[i] << endl;
    }
    L[n1] = 1000000000;
    R[n2] = 1000000000;
    i = 0;
    j = 0;
    for(int k = l; k < r; k++){
        c += 1;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
        }else{
            A[k] = R[j];
            j += 1;
        }
    }
}

void mergesort(int A[], int l, int r){ //分割
    int mid;
    if ((l + 1) < r){
        mid = (l + r) / 2;
        mergesort(A, l, mid);
        mergesort(A, mid, r);
        merge(A, l, mid, r);
    }
}

int main(){
    int n, r, l = 0, A[500000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    r = n;
    //mid = (r + l)/2;
    mergesort(A, 0, r);

    for(int i = 0; i < n - 1; i++){
        cout << A[i] << " ";
    }
    cout << A[n - 1] << endl << c << endl;
    return 0;
}



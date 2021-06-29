#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int cnt;

void merge(vector<int> &A, int L, int mid, int R);

void mergeSort(vector<int>& A, int p, int r);

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cnt = 0;
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i){
        if(i > 0)
            cout << " ";
        cout << arr[i];
    }
    cout << endl << cnt << endl;
    cin.get();
    cin.get();
    return 0;
}

void merge(vector<int>& A, int p, int mid, int r){
    int n1 = mid-p+1, n2 = r-mid;
    vector<int> L(n1+1), R(n2+1);
    for (int i=0; i<n1; ++i){
        L[i] = A[p + i];
    }
    for (int i=0; i<n2; ++i){
        R[i] = A[mid + 1 + i];
    }
    L[n1] = R[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k=p; k<=r; ++k){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }
        else{
            A[k] = R[j++];
        }
    }
}

void mergeSort(vector<int>& A, int p, int r){
    if(p >= r)
        return;
    int mid = p + (r - p) / 2;
    mergeSort(A, p, mid);
    mergeSort(A, mid + 1, r);
    merge(A, p, mid, r);
}

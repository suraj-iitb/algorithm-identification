#include <bits/stdc++.h>
using namespace std;

int cnt;
void merge(vector<int> &A, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1+1);
    vector<int> R(n2+1);
    for(int i = 0;i < n1; i++)
        L[i] = A[left + i];
    for(int i = 0; i < n2; i++)
        R[i] = A[mid + i];
    L[n1] = 1000000000;
    R[n2] = 1000000000;
    int i=0, j=0;
    for(int k = left ; k < right ; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
void mergeSort(vector<int> &A, int left , int right){
    if (left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A,left, mid);
        mergeSort(A,mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    cnt = 0;
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i < n; i++)
        cin >> A[i];
    mergeSort(A, 0, n);
    for(int i=0; i < n-1; i++){
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl;
    cout << cnt << endl;
}

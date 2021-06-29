#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define SENTINEL 1000000000
int count = 0;
void Merge(vector<int>& A,int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1+1),R(n2+1);
    rep(i,n1){
        L[i] = A[left + i];
    }
    rep(i,n2){
        R[i] = A[mid + i];
    }
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    int i = 0;
    int j = 0;
    for(int k=left;k<right;k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i = i+1;
        }else{
            A[k] = R[j];
            j = j+1;
        }
        count++;
    }
}
void MergeSort(vector<int>& A,int left,int right){
    if((left + 1) < right){
        int mid = (left+right)/2;
        MergeSort(A, left, mid);
        MergeSort(A, mid, right);
        Merge(A, left, mid, right);
    }
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N+1);
    rep(i,N){
        cin >> A[i];
    }
    A[N] = SENTINEL;
    MergeSort(A,0,N);
    rep(i,N){
        cout << A[i];
        if(i < N-1)cout << " ";
    }
    cout << endl << count << endl;
    return 0;
}

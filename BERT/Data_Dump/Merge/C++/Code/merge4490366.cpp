#include <iostream>
using namespace std;

int ans(0);
void merge(int A[],int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1],R[n2];
    for(int i=0;i<=n1-1;i++){
        L[i] = A[left+i];
    }
    for(int i=0;i<=n2-1;i++){
        R[i] = A[mid+i];
    }
    L[n1] = 2147483646;
    R[n2] = 2147483646;
    int i(0),j(0);
    for(int k=left;k<=right-1;k++){
        ans++;
        if(L[i]<=R[j]){
            A[k] = L[i];
            i += 1;
        }else{
            A[k] = R[j];
            j += 1;
        }
    }
}

void mergeSort(int A[],int left,int right){
    if(left+1<right){
        int mid = (left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    mergeSort(A,0,n);
    for(int i=0;i<n;i++){
        if(i+1==n){
            cout << A[i] << endl;
        }else
            cout << A[i] << " ";
    }
    cout << ans << endl;
    return 0;
}

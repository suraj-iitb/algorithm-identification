#include<iostream>
using namespace std;
int ct,L[500000],R[500000];

void merge(int A[],int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0;i<n1;i++)L[i] = A[left + i];
    for(int i=0;i<n2;i++)R[i] = A[mid + i];
    L[n1] = R[n2] = 2000000000;
    int i=0;
    int j = 0;
    for(int k=left;k<right;k++){
        ct++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i = i + 1;
        }else{
            A[k] = R[j];
            j = j+1;
        }
    }
}

void mergeSort(int A[],int left,int right){
    if(left + 1 < right){
        int mid = (left + right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int main(){
    int n,S[500000];
    cin >> n;
    ct = 0;
    for(int i=0;i<n;i++)cin >> S[i];

    mergeSort(S,0,n);
    for(int i=0;i<n;i++){
        if(i != 0)cout << " " ;
        cout << S[i];
    }
    cout << endl;
    cout << ct << endl;
    return 0;    
}

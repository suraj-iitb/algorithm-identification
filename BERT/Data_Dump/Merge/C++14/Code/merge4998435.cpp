#include<iostream>
using namespace std;
#define INFTY 2000000000
#define MAX 500000

int L[MAX/2+2],R[MAX/2+2];
int count;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0;i<n1;i++){
        L[i] = A[left + i];
    }
    for(int i = 0;i<n2;i++){
        R[i] = A[mid + i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;
    int i = 0, j = 0;
    for(int k=left;k<right;k++){
        count ++;
        if(L[i] <= R[j]){
        A[k] = L[i];
        i = i + 1;
        }else{ 
            A[k] = R[j];
            j = j + 1;
        }
    }
}
  
void mergeSort(int A[], int left, int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
int main(){
    int A[MAX],n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    count =0;
    mergeSort(A,0,n);
    for(int i=0;i<n;i++){
        if(i>0)cout<<" ";
        cout <<A[i];
    }
    cout << endl;
    cout << count <<endl;
    return 0;
}

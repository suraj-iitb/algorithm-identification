#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAX 500000
#define INF 1000000000
int cut =0;
int L[MAX],R[MAX];
void marge(int *A,int left,int mid,int right,int n){
    int n1 = mid - left;
    int n2 = right - mid;
    
    for(int i=0;i<n1;i++) L[i] = A[left+i];
    for(int i=0;i<n2;i++) R[i] = A[mid+i];
    L[n1] = INF;
    R[n2] = INF;
    int i=0;
    int j=0;
    for(int k=left;k<right;k++){
        cut++;
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}
void margeSort(int *A,int n,int left,int right){
    
    if(left+1 < right){
        int mid = (left+right)/2;
        margeSort(A,n,left,mid);
        margeSort(A,n,mid,right);
        marge(A,left,mid,right,n);
    }
}

int main(){
    int A[MAX];
    int n;
    cut =0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    margeSort(A,n,0,n);
    for(int i=0;i<n;i++){
        if(i !=0)putchar(' ');
        cout << A[i];
    }
    putchar('\n');

    cout << cut << endl;
    return 0;
}

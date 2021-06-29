#include <iostream>

using namespace std;
int A[500000];
int cnt;
void Merge(int A[],int left,int mid,int right){
    int n1 = mid-left+1;
    int n2 = right - mid;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++){
        L[i] = A[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = A[mid+1+i];
    }
    L[n1] = 2000000000;
    R[n2] = 2000000000;
    int i=0,j=0;
    for(int k=left;k<right+1;k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}
void mergeSort(int A[],int left,int right){
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid+1,right);
        Merge(A,left,mid,right);
    }
}
int main()
{
    int n;
    cnt = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    mergeSort(A,0,n-1);
    for(int i=0;i<n;i++){
        if(i>0) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}


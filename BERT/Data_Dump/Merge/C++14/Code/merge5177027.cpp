#include <bits/stdc++.h>
using namespace std;

int n,A[500000];
int cnt = 0;

void merge(int A[],int lef,int mid,int rig){
    int n1,n2;
    n1 = mid - lef;
    n2 = rig - mid;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++){
        L[i] = A[lef + i];
    }
    for(int i=0;i<n2;i++){
        R[i] = A[mid + i];
    }
    L[n1] = 1000000001;
    R[n2] = 1000000001;
    int i = 0;
    int j = 0;
    for(int k=lef;k<rig;k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
}

void mergeSort(int A[],int lef,int rig){
    int mid;
    if(lef+1 < rig){
        mid = (lef + rig) / 2;
        mergeSort(A,lef,mid);
        mergeSort(A,mid,rig);
        merge(A,lef,mid,rig);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    mergeSort(A,0,n);
    for(int i=0;i<n;i++){
        if(i!=n-1){
            cout<<A[i]<<" ";
        }else{
            cout<<A[n-1]<<endl;
        }
    }
    cout<<cnt<<endl;
    return 0;   
}


#include<iostream>
#define SETMINTAL 2000000000
using namespace std;

int cnt=0;
int L[250005],R[250005];

void myMerge(int A[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int i,j;
    for(int i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=A[mid+i];
    }
    L[n1]=R[n2]=SETMINTAL;
    i=0; j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
    }
}

void MergeSort(int A[],int left,int right){
    int mid=0;
    if(left+1<right){
        mid=(right+left)/2;
        MergeSort(A,left,mid);
        MergeSort(A,mid,right);
        myMerge(A,left,mid,right);
    }
}

int main(){
    int A[500005];
    int n;
    cin>>n;
    cnt=0;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    MergeSort(A,0,n);
    for(int i=0;i<n;i++){
        if(i) cout<<' ';
        cout<<A[i];
    }
    cout<<endl<<cnt<<endl;
    return 0;
}


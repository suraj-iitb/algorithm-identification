#include<iostream>
using namespace std;
long long c=0;

void Merge(long int A[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    long int L[n1+1];
    long int R[n2+1];
    for(int i=0;i<n1;i++)
        {L[i]=A[left+i];}
    for(int i=0;i<n2;i++)
        {R[i]=A[mid+i];}
    L[n1]=5000000000;
    R[n2]=5000000000;
    int i=0;
    int j=0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j])
            A[k]=L[i++];
        else
            A[k]=R[j++];
        c++;
    }
}

void MergeSort(long int A[],int left,int right){
    if(left + 1< right){
        int mid=(left+right)/2;
        MergeSort(A,left,mid);
        MergeSort(A,mid,right);
        Merge(A,left,mid,right);
    }
}

int main(){
    int N;
    cin>>N;
    long int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    MergeSort(A,0,N);

    for(int i=0;i<N-1;i++){
        cout<<A[i]<<" ";
    }
    cout<<A[N-1]<<endl<<c<<endl;
    return 0;
}


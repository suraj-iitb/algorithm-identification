#include<iostream>
using namespace std;

struct card{
    char mark;
    int value;
};

int partition(card A[],int p,int r){
    int i,par;
    i=p-1;
    for(int j=p;j<r;j++){
        if(A[j].value<=A[r].value){
            i+=1;
            swap(A[i],A[j]);
        }
    }
    i+=1;
    swap(A[i],A[r]);
    return i;
}

void quicksort(card A[],int p,int r){
    int q;
    if(p<r){
        q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

void merge(card A[],int left,int mid,int right){
    int n1,n2,i,j;
    n1=mid-left;
    n2=right-mid;
    card L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=A[mid+i];
    }
    L[n1].value=1000000000;
    R[n2].value=1000000000;
    i=0;
    j=0;
    for(int k=left;k<right;k++){
        if(L[i].value<=R[j].value){
            A[k]=L[i];
            i=i+1;
        }else{
            A[k]=R[j];
            j=j+1;
        }
    }
}
void mergeSort(card A[],int left,int right){
    if(left+1<right){
        int mid;
        mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int main(){
    int n,par,i;
    bool stable;
    cin>>n;
    card A[n],B[n];
    for(int k=0;k<n;k++){
        cin>>A[k].mark>>A[k].value;
    }

    for(int k=0;k<n;k++){
        B[k]=A[k];
    }

    quicksort(A,0,n-1);
    mergeSort(B,0,n);

    stable=0;
    for(int i=0;i<n;i++){
        if(A[i].mark!=B[i].mark){
            stable=1;
        }
    }

    if(stable==0){
        cout<<"Stable"<<endl;
    }else{
        cout<<"Not stable"<<endl;
    }
    
    for(int j=0;j<n;j++){
        cout<<A[j].mark<<" "<<A[j].value<<endl;
    }

    return 0;
}

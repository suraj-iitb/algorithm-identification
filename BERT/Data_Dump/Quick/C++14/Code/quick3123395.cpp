#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef pair<char,int> P;
P L[60000],R[60000];
int partition(P A[], int p, int r){
    int i;
    P t,x;
    x=A[r];
    i=p-1;
    for(int j=p;j<r;j++){
        if(A[j].second<=x.second){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quickSort(P A[], int p, int r){
    if(p<r){
        int q=partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
    return ;
}

void merge(P C[], int left, int mid, int right){
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++){
        L[i]=C[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=C[mid+i];
    }
    L[n1].second=R[n2].second=INF;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i].second<=R[j].second){
            swap(C[k],L[i]);
            i++;
        }
        else{
            swap(C[k],R[j]);
            j++;
        }
    }
}
void mergeSort(P C[], int left, int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(C,left,mid);
        mergeSort(C,mid,right);
        merge(C,left,mid,right);
    }
    return ;
}

int main(){
    P A[100000],C[100000];
    int n;
    cin>>n;
    char a;
    int b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        A[i].first=a;
        A[i].second=b;
        C[i].first=a;
        C[i].second=b;
    }
    quickSort(A,0,n-1);
    mergeSort(C,0,n);
    bool flag=true;
    for(int i=0;i<n;i++){
        if(A[i]!=C[i]) flag=false;
    }
    if(flag) cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i].first<<" "<<A[i].second<<endl;
    }
    
    return 0;
}


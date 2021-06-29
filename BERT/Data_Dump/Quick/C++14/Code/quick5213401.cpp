#include <bits/stdc++.h>
using namespace std;

struct Card{
    char suit;
    int num;
};

void merge(vector<Card> &A,int left,int right){
    int mid=(left+right)/2;
    vector<Card> L(mid-left+1),R(right-mid+1);
    for(int i=0;i<mid-left;i++){
        L.at(i)=A.at(left+i);
    }
    for(int i=0;i<right-mid;i++){
        R.at(i)=A.at(mid+i);
    }
    L.at(mid-left)={'c',1000000001};
    R.at(right-mid)={'c',1000000001};
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L.at(i).num<=R.at(j).num){
            A.at(k)=L.at(i);
            i++;
        }else{
            A.at(k)=R.at(j);
            j++;
        }
    }
    return;
}

void mergeSort(vector<Card> &A,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,right);
    }
}

int partition(vector<Card> &A,int p,int r){
    int x=A.at(r).num;
    int i=p-1;
    for(int j=p;j<r;j++){
        if(A.at(j).num<=x){
            i++;
            swap(A.at(i),A.at(j));
        }
    }
    swap(A.at(i+1),A.at(r));
    return i+1;
}

void quickSort(vector<Card> &A,int p,int r){
    if(p<r){
        int m=partition(A,p,r);
        quickSort(A,p,m-1);
        quickSort(A,m+1,r);
    }
    return;
}

void print(vector<Card> &A,int n){
    for(int i=0;i<n;i++){
        cout << A.at(i).suit << " " << A.at(i).num << endl;
    }
    return;
}

bool isStable(vector<Card> &A,vector<Card> &B,int n){
    for(int i=0;i<n;i++){
        if(A.at(i).suit!=B.at(i).suit){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<Card> A(n),B(n);
    for(int i=0;i<n;i++){
        cin >> A.at(i).suit >> A.at(i).num;
    }
    B=A;
    quickSort(A,0,n-1);
    mergeSort(B,0,n);
    if(isStable(A,B,n)){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    print(A,n);
    return 0;
}

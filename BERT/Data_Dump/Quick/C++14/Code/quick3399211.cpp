//ALDS1_6_C_QuickSort.cpp
#include<bits/stdc++.h>
using namespace std;
const int INF=2E9;
typedef pair<int,int> Pair;
typedef long long LL;
int cnt=0;

struct card{
    char suit;
    int num;
};

void merge(card A[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    card *L=new card[n1+1];
    card *R=new card[n2+1];
    for(int i=0;i<n1;i++) L[i]=A[left+i];
    for(int i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1].num=R[n2].num=INF;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i].num<=R[j].num){
            A[k]=L[i];
            i=i+1;
        }else {
            A[k]=R[j];
            j=j+1;
        }
        cnt++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(card A[],int left,int right){
    if(left+1<right){
        int mid =(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int partition(card A[],int p,int r){
    int x=A[r].num;
    int i=p-1;
    card tmp;
    for(int j=p;j<r;j++){
        if(A[j].num<=x){
            i++;
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    tmp=A[i+1];
    A[i+1]=A[r];
    A[r]=tmp;
    return i+1;
}

void quickSort(card A[],int p, int r){
    if(p<r){
        int q=partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}

int main(){
    int n;
    cin >> n;
    card A[100100];
    card M[100100];
    char str[10];
    for(int i=0;i<n;i++){
        scanf("%s %d",str,&A[i].num);
        A[i].suit=str[0];
        M[i]=A[i];
    }
    quickSort(A,0,n-1);
    mergeSort(M,0,n);
    bool stable=1;
    for(int i=0;i<n;i++){
        if(A[i].suit!=M[i].suit) stable=0;
    }
    if(stable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    for(int i=0;i<n;i++){
        cout << A[i].suit << " " << A[i].num << endl;
    }

    return 0;
}


//ALDS1_5_A_ExhaustiveSearch

#include<bits/stdc++.h>
using namespace std;
const int INF=2E9;
typedef pair<int,int> Pair;
typedef long long LL;
int cnt=0;

void merge(int A[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int *L=new int[n1+1];
    int *R=new int[n2+1];
    for(int i=0;i<n1;i++) L[i]=A[left+i];
    for(int i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1]=R[n2]=INF;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j]){
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

void mergeSort(int A[],int left,int right){
    if(left+1<right){
        int mid =(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int main(){
    int n;
    int A[500100];
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    mergeSort(A,0,n);
    for(int i=0;i<n;i++){
        cout << A[i];
        if(i==n-1) cout << endl;
        else cout << " ";
    }
    cout << cnt << endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int cnt = 0;
void merge(vector<int> &A,int left,int mid,int right){
    int n1 = mid-left;
    int n2 = right - mid;
    vector<int> L(n1+1);
    vector<int> R(n2+1);
    iota(L.begin(),L.end(),0);
    iota(R.begin(),R.end(),0);
    for(int i=0;i<=n1-1;i++){
        L[i] = A[left+i];
    }
    for(int i=0;i<=n2-1;i++){
        R[i] = A[mid+i];
    }
    L[n1] = INF;
    R[n2] = INF;
    int i=0;
    int j=0;
    for(int k=left;k<=right-1;k++){
        if(L[i]<=R[j]){
            cnt++;
            A[k]=L[i];
            i = i+1;
        }else{
            cnt++;
            A[k] = R[j];
            j = j+1;
        }
    }
}
void mergeSort(vector<int> &A,int left,int right){
    if(left+1<right){
        int mid = (left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}
int main(){
    int n;cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    mergeSort(a,0,n);
    for(int i=0;i<n;i++){
        cout << a[i];
        cout << ((i==n-1)?"\n":" ");
    }
    cout << cnt << endl;
}

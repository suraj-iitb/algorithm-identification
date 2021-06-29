#include <bits/stdc++.h>
using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

vector<int> L(MAX/2+2),R(MAX/2+2);
int cnt;

void merge(vector<int> *A,int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++) L.at(i) = (*A).at(left + i);
    for(int i = 0; i < n2; i++) R.at(i) = (*A).at(mid + i);
    L.at(n1) = R.at(n2) = SENTINEL;
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(L.at(i) <= R.at(j)){
            (*A).at(k) = L.at(i);
            i++;
            
        }else{
            (*A).at(k) = R.at(j);
            j++;
            
        }
    }
}

void mergeSort(vector<int> *A, int n, int left, int right){
    if(left + 1 < right){
        int mid = (left + right)/2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main(){
    vector<int> A(MAX);
    int n;
    cnt = 0;
    
    cin >> n;
    for(int i = 0;i<n;i++) cin >> A.at(i);

    mergeSort(&A,n,0,n);
    for(int i = 0;i<n;i++){
        if(i) cout << " ";
        cout << A.at(i);
    }

    cout << endl;

    cout << cnt << endl;

    return 0;
}



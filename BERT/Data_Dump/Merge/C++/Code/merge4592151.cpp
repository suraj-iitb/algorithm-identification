#include <bits/stdc++.h>
const int INF=INT_MAX; 
using namespace std;
void merge_sort(vector<int>& A, int l, int r);
void merge(vector<int>& A, int l, int m, int r);

int c = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    merge_sort(A, 0, n);
    for(int i=0;i<n;i++) cout << A[i] << " \n"[i==n-1];
    cout << c << endl;
    
    return 0;
}


void merge(vector<int>& A, int l, int m, int r){
    
    int n1 = m - l;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i] = A[l+i];
    for(int i=0;i<n2;i++) R[i] = A[m+i];
    int i=0,j=0;
    for(int k=l;k<r;k++){
    	c++;
        if( i<n1 and (j>=n2 or L[i]<=R[j])){
            A[k] = L[i];
            i++;
        }else if(j<n2){
            A[k] = R[j];
            j++;
        }
    }
    
}
void merge_sort(vector<int>& A, int l, int r){
    if(l+1<r){
        int m = ((l+r)/2);
        merge_sort(A, l, m);
        merge_sort(A, m, r);
        merge(A, l, m, r);
    }
}

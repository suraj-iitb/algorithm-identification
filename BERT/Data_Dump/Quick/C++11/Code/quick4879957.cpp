#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<char,int>> vpci;

int partition1(vpci &a, int p, int r){
    int x = a[r].second;
    int i = p -1 ;
    for(int j = p; j <= r; j++)
        if(x >= a[j].second)
            swap(a[j],a[++i]);
    return i;
}
void quickSort(vpci &A, int p, int r){
    if(p < r){
        int q = partition1(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}
void merge(vpci &A, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vpci L(n1+1);
    vpci R(n2+1);
    for(int i = 0;i < n1; i++)
        L[i] = A[left + i];
    for(int i = 0; i < n2; i++)
        R[i] = A[mid + i];
    L[n1].second = 1000000000;
    R[n2].second = 1000000000;
    int i=0, j=0;
    for(int k = left ; k < right ; k++){
        if(L[i].second <= R[j].second){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
void mergeSort(vpci &A, int left , int right){
    if (left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A,left, mid);
        mergeSort(A,mid, right);
        merge(A, left, mid, right);
    }
}


int main(){
    int n;
    cin >> n;
    vector<pair<char,int>> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i].first;
        cin >> A[i].second;
    }
    vector<pair<char,int>> B(n);
    copy(A.begin(), A.end(), B.begin());
    quickSort(A, 0,  n-1);
    mergeSort(B, 0,   n);
    if(A == B){
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }
    for(int i=0; i<n; i++){
        cout << A[i].first << " " << A[i].second << endl;
    }

    
}

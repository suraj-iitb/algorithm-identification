#include    <bits/stdc++.h>
using   namespace   std;

#define INF (1<<30)

long C=0;

void    merge(vector<int> &A, const int &left, const int &mid, const int &right) {
    int n1 = mid - left;
    int n2 = right - mid;
    // L[0...n1], R[0...n2] を生成
    vector<int> L;
    vector<int> R;
    for (int i = 0; i<n1; i++)
        L.push_back(A.at(left+i));
    for (int i = 0; i<n2; i++)
        R.push_back(A.at(mid+i));
    L.push_back(INF);
    R.push_back(INF);
    int i=0;
    int j=0;
    for (int k=left; k<right; k++) {
        if (L.at(i)<=R.at(j)) {
            A.at(k)=L.at(i);
            i++;
        } else {
            A.at(k)=R.at(j);
            j++;
        }
        C++;
    }
}

void    mergeSort(vector<int> &A, const int left, const int right) {
    if (left+1<right) {
        int mid=(left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n;
    cin >>n;
    vector<int> A(n, 0);
    for (int i=0; i<n; i++)
        cin >>A.at(i);
    mergeSort(A, 0, n);
    for (int i=0; i<n; i++)
        if (i==0)
            cout <<A.at(i);
        else
            cout <<' ' <<A.at(i);
    cout <<endl;
    cout <<C <<endl;
    return 0;
}


#include<bits/stdc++.h>//alias g='g++ -std=c++17 pra.cpp'
using namespace std;
#define rep(i, n) ;for(int i=0; i<(n); i++)
using veci = vector<int>;
int INF = INT_MAX;
int a[1000000];
int completed[1000000];
int L[300000];
int R[300000];
int counter=0;
void merge(int a[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i=0; i<n1; i++) L[i] = a[left + i];
    for (int i=0; i<n2; i++) R[i] = a[mid + i];
    L[n1] = INF;//番兵
    R[n2] = INF;
    int i=0;
    int j=0;
    for (int k=left; k<right; k++){
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        counter++;
    }
}
void mergeSort(int a[], int left, int right){
    if (left+1 < right){//要素が一つになるまで分割する
        int mid = (left + right)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}
int main(){
    int n; cin >> n;
    rep(i, n) cin >> a[i];
    veci b(n);
    mergeSort(a, 0, n);
    rep(i, n){
        if (i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << counter << endl;
}

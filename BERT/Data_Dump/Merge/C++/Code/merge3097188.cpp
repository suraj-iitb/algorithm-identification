#include <iostream>
#include <cstdio>
using namespace std;
int cont = 0;
 
int L[250005], R[250005];
 
 
void merge(int S[], int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int t = 0; t < n1; t++)L[t] = S[left + t];
    for (int t = 0; t < n2; t++)R[t] = S[mid + t];
    L[n1] = R[n2]= 2000000000;
 
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        cont++;
        if (L[i] <= R[j]) {
            S[k] = L[i];
            i++;
        }
        else {
            S[k] = R[j];
            j++;
        }
    }
 
}
 
void mergeSort(int S[],int n,int left,int right) {
    int mid = (left + right) / 2;
    if (left + 1 < right) {
        mergeSort(S, n, left, mid);
        mergeSort(S, n, mid, right);
        merge(S, n, left, mid,right);
    }
}
 
int main() {
    int n;
    cin >> n;
    int S[500005];
    for (int t = 0; t < n; t++) {
        scanf("%d", &S[t]);
    }
 
    mergeSort(S,n,0,n);
 
    for (int t = 0; t < n; t++) {
        if (t)cout << " ";
        cout << S[t];
    }
    cout << "\n";
    cout <<cont << "\n";
 
    return 0;
}

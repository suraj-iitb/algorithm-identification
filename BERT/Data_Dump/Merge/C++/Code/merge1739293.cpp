#include<iostream>
#define SENTINEL 2000000000
#define MAX 500000
using namespace std;

int cnt;
int L[MAX / 2+2],R[MAX / 2+2];

void merge(int A[], int n, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = R[n2] = SENTINEL;
    int i = 0;
    int j = 0;
    for (int k = left; k < right ; k++){
        cnt++;
        if (L[i] < R[j]){
            A[k] = L[i];
            i = i + 1;
            
        } else {
            A[k] = R[j];
            j = j + 1;
        }
    }
}
void mergeSort(int A[], int n, int left, int right)
{
    if (left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main()
{
    int n;
    int S[MAX];
    cnt = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> S[i];
    }
    mergeSort(S, n, 0, n);
    for (int i = 0; i < n; i++ ){
        if (i) cout << " ";
        cout << S[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
    
}

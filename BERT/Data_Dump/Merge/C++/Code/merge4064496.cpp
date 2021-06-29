#include<iostream>
using namespace std; 

#define MAX 1000000001
#define ARRAY_SIZE 500001

int A[ARRAY_SIZE];
int ans = 0;
int n;

void print(){
    for(int i = 0; i < n; i++){
        if(i != 0)  cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << ans << endl;
}

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1];
    int R[n2 + 1];
    for(int i = 0; i < n1; i++) L[i] = A[left + i];
    for(int i = 0; i < n2; i++) R[i] = A[mid + i];
        L[n1] = MAX;
        R[n2] = MAX;

        int li = 0;
        int ri = 0;

        for(int i = left; i < right; i++){
            if(L[li] <= R[ri]){
            A[i] = L[li];
            li++;
            }else{
                A[i] = R[ri];
                ri++;
            }
            ans++;
        }
    }

void mergesort(int A[], int left, int right){
    if(left + 1 < right){
    int mid = (left + right) / 2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left, mid, right);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    mergesort(A,0,n);
    print();
    return 0;
}

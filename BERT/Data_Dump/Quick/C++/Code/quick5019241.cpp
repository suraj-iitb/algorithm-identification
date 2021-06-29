#include <iostream>
using namespace std;
#define MAX 100000
#define SENTINEL 2000000000

struct card{
    char nam;
    int num;
};

card A[MAX], B[MAX], L[MAX/2+2], R[MAX/2+2];

int partition(int p, int r){
    int x = A[r].num;
    int i = p - 1;
    card a;
    for(int j = p; j < r;j++){
        if(A[j].num <= x){
            i = i +1;
            a = A[i];
            A[i] = A[j];
            A[j] = a;
        }
    }
    a = A[i+1];
    A[i+1] = A[r];
    A[r] = a;
    return i+1;
}

void quicksort(int p, int r){
    if(p < r){
        int q = partition(p, r);
        quicksort(p, q-1);
        quicksort(q+1, r);
    }
}

void merge(card A[], int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1].num = R[n2].num = SENTINEL;
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        if(L[i].num <= R[j].num){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
        }
    }

}

void mergeSort(card A[], int n, int left, int right){
    int mid;
    if(left + 1 < right){
        mid = (left + right)/2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i].nam >> A[i].num;
        B[i].nam = A[i].nam;
        B[i].num = A[i].num;
    }

    quicksort(0, n-1);
    mergeSort(B, n, 0, n);

    for(int i = 0; i < n; i++){
        if(A[i].nam != B[i].nam){
            cout << "Not stable" << endl;
            break;
        }
        if(i == n-1) cout << "Stable" <<endl;
    }

    for(int i = 0; i < n; i++){
        cout << A[i].nam << " " << A[i].num << endl;
    }
    return 0;
}

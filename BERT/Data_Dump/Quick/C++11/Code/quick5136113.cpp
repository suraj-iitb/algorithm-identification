#include<iostream>
#include<vector>
#include<climits>
using namespace std;

typedef struct {
    char face;
    int number;
} card;

void merge(vector<card> &A, int L, int mid, int R);
void mergeSort(vector<card>& A, int p, int r);
int partition(vector<card> &arr, int p, int r);
void QuickSort(vector<card> &arr, int p, int r);

int main(){
    int n;
    cin >> n;
    vector<card> arr1(n);
    for (int i = 0; i < n; ++i){
        cin >> arr1[i].face >> arr1[i].number;
    }
    vector<card> arr2 = arr1;
    QuickSort(arr1, 0, n - 1);
    mergeSort(arr2, 0, n - 1);
    bool stable = 1;
    for (int i = 0; i < n; ++i){
        if(arr1[i].face != arr2[i].face)
            stable = 0;
    }
    stable == 0 ? cout << "Not stable\n" : cout << "Stable\n";
    for (int i=0; i<n; ++i){
        cout << arr1[i].face << " " << arr1[i].number << endl;
    }
    cin.get();
    cin.get();
    return 0;
}

int partition(vector<card>& arr, int p, int r){
    int x = arr[r].number;
    int i = p - 1;
    for (int j = p; j < r; ++j){
        if(arr[j].number <= x){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i + 1;
}

void QuickSort(vector<card> &arr, int p, int r){
    if(p<r){
        int pivot = partition(arr, p, r);
        QuickSort(arr, p, pivot - 1);
        QuickSort(arr, pivot + 1, r);
    }
}

void merge(vector<card>& A, int p, int mid, int r){
    int n1 = mid-p+1, n2 = r-mid;
    vector<card> L(n1+1), R(n2+1);
    for (int i=0; i<n1; ++i){
        L[i] = A[p + i];
    }
    for (int i=0; i<n2; ++i){
        R[i] = A[mid + 1 + i];
    }
    L[n1].number = R[n2].number = INT_MAX;
    int i = 0, j = 0;
    for (int k=p; k<=r; ++k){
        if(L[i].number <= R[j].number){
            A[k] = L[i++];
        }
        else{
            A[k] = R[j++];
        }
    }
}

void mergeSort(vector<card>& A, int p, int r){
    if(p >= r)
        return;
    int mid = p + (r - p) / 2;
    mergeSort(A, p, mid);
    mergeSort(A, mid + 1, r);
    merge(A, p, mid, r);
}

#include <iostream>
using namespace std;

int count;

void merge(int* L, int* R, int* array, int left, int mid, int right)
{
    for(int i=left; i<mid; ++i) L[i - left] = array[i];
    for(int i=mid; i<right; ++i) R[i - mid] = array[i];
    int l = 0, r = 0;
    for(int i=left;i<right;++i)
    {
        if(l >= mid - left) array[i] = R[r++];
        else if(r >= right - mid) array[i] = L[l++];
        else if(R[r] < L[l]){
            array[i] = R[r++];
        }
        else
        {
            array[i] = L[l++];
        }
        ++count;
    }
}

void mergeSort(int* L, int* R, int* array, int left, int right)
{
    if(left < right - 1){
        int mid = (left + right) / 2;
        mergeSort(L, R, array, left, mid);
        mergeSort(L, R, array, mid, right);
        merge(L, R, array, left, mid, right);
    }
}

void printArray(int* array, int n)
{
    for(int i=0;i<n;++i)
    {
        if(i) cout << " ";
        cout << array[i];
    }
    cout << endl;
}

int main()
{
    int L[250000], R[250000], A[500000];
    int n;
    count = 0;
    cin >> n;
    for(int i=0;i<n;++i) cin >> A[i];
    mergeSort(L, R, A, 0, n);
    printArray(A, n);
    cout << count << endl;
}

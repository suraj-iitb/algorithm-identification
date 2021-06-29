#include <iostream>
#define SENTINEL 1000000001
using namespace std;
int comp = 0;

void Merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int arr1[n1] = {};
    int arr2[n2] = {};
    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[mid + i];
    }
    arr1[n1] = SENTINEL;
    arr2[n2] = SENTINEL;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++) {
        comp++;
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
    }
}

void MergeSort(int arr[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid, right);
        Merge(arr, left, mid, right);
    }
}

int main() {
    int pickles, i;
    cin >> i;
    int array[i] = {};
    for (int j = 0; j < i; j++) {
        cin >> array[j];
    }
    MergeSort(array, 0, i);
    for (int k = 0; k < i; k++) {
        if (k != i - 1) cout << array[k] << " ";
        else cout << array[k] << endl;
    }
    cout << comp << endl;
}

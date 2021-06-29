#include<iostream>
using namespace std;

#define MAX 500007
#define INFTY 2000000000
int S[MAX];
int compareCount;
int L[MAX/2+2], R[MAX/2+2];

void merge(int S[], int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = S[left+i]; 
    for (int i = 0; i < n2; i++) R[i] = S[mid+i];
    
    L[n1] = R[n2] = INFTY;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) S[k] = L[i++];
        else S[k] = R[j++];
        compareCount++;
    }
}

void mergeSort(int S[], int n, int left, int right) {
    if (left + 1 < right) { // if left + 1 == right (only one elements), it's a leaf, so already sorted!
        int mid = (left + right) / 2;
        mergeSort(S, n, left, mid);
        mergeSort(S, n, mid, right);
        merge(S, n, left, mid, right);
    }
}

int main(void)
{
    int n;
    compareCount = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> S[i];
    
    mergeSort(S, n, 0, n);
    
    for (int i = 0; i < n-1; i++) cout << S[i] << " ";
    cout << S[n-1] << endl;
    cout << compareCount << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int count = 0;

void merge(vector<int> &A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    for(int i=0;i<n1;i++) {
        L[i] = A[left + i];
    }
    for(int i=0;i<n2;i++) {
        R[i] = A[mid + i]; 
    }
    L[n1] = 1000000010;
    R[n2] = 1000000010;
    int i=0, j=0;
    for(int k = left; k < right; k++) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
            count++;
        } else {
            A[k] = R[j];
            j++;
            count++;
        }
    }
}

void merge_sort(vector<int> &A, int left, int right) {
    if(left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
//    ifstream in("input.txt");
//    cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;
    vector<int> S(n);
    for(int i=0;i<n;i++) {
        cin >> S[i];
    }
    
    merge_sort(S, 0, n);
    
    for(int i=0;i<n;i++) {
        if(i!=0) cout << " ";
        cout << S[i];
    }
    cout << endl;
    cout << count << endl;
    
    return 0;
}

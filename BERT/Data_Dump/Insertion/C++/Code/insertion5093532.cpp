#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i];
        
        if(i != n - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

int main(void){
    int n;
    cin >> n;
    
    int A[n];
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    printArray(A, n);
    
    for(int i = 1; i < n; i++) {
        int v = A[i];
        int j = i - 1;
        
        while(j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = v;
        printArray(A, n);
    }
    
    return 0;
}


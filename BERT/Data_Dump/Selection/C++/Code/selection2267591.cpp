#include <iostream>
using namespace std;

int count = 0;

void selectionSort(int A[], int n){
    for(int i = 0; i < (n - 1); i++){
        int minj = i;
        for(int j = i + 1; j < n; j++){
            if(A[minj] > A[j]) minj = j;
        }
        if(minj != i){
            swap(A[minj], A[i]);
            count++;
        }
    }
}


int main(void){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    
    selectionSort(A, n);
    
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}

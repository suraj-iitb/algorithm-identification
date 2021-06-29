#include <iostream>
using namespace std;

int selectionSort(int A[], int n) {
    int counter = 0;
    
    for(int i = 0; i < n; i++) {
        int minj = i;
        
        for(int j = i; j < n; j++) {
            if(A[j] < A[minj]) {
                minj = j;
            }
        }
        
        int temp = A[i];
        A[i] = A[minj];
        A[minj] = temp;
        if(i != minj) counter++;
    }
    return counter;
}

int main(void){
    // Here your code !
    int A[100], n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int counter = selectionSort(A,n);
    
    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << counter << endl;
}

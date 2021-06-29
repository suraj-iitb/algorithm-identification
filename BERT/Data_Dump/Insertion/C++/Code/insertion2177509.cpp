#include<iostream>
#include<vector>
using namespace std;

int main() {
    
    int size;
    int A[100];
    cin >> size;
    for(int i = 0; i < size; ++i) {
        cin >> A[i];
    }

    int key;
    for(int i = 0; i < size; ++i) {
        int j = i - 1;
        while(j >= 0 && A[j] > A[j + 1]) {
            key = A[j + 1];
            A[j + 1] = A[j];
            A[j] = key;
            --j;
        }
        for(int k = 0; k < size; ++k) {
            cout << A[k];
            if(k != size - 1) cout << " ";
        }
        cout << endl;
    }
}

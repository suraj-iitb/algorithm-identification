#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> A, int N);

int main(void){
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }
    
    insertionSort(A, N);
    
}

void insertionSort(vector<int> A, int N) {
    for (int i=0; i<N; i++) {
        int value = A.at(i);
        int j = i-1;
        
        while (j >= 0 && A.at(j) > value) {
            A.at(j+1) = A.at(j);
            j--;
        }
        A.at(j+1) = value;
        
        for (int k=0; k<N; k++) {
            cout << A.at(k) ;
            if (k != N-1) {
                cout << ' ';
            } else {
                cout << endl;
            }
        }
        
    }
}



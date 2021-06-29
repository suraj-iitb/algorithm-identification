#include <bits/stdc++.h>
using namespace std;

int selectionSort(vector<int>& A, int N){
    int sw = 0;
    int minj;
    for(int i = 0; i < N-1; i++){
        minj = i;
        for (int j = i; j < N; j++){
            if(A.at(j) < A.at(minj)){
                minj = j;
            }
        }
        swap(A.at(i), A.at(minj));
        if (i != minj) sw++;
    }
    return sw;
}

int main() {
    vector<int> A(100);
    int N, sw;
    cin >> N;
    
    for (int i = 0; i < N; i++) cin >> A.at(i);
    sw = selectionSort(A, N);
    for (int j = 0; j < N; j++){
        if (j > 0)  cout << " ";
        cout << A.at(j);
    }
    cout << endl;
    cout << sw << endl;
    
    return 0;
}

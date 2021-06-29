#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int>& A, int N){
    int sw = 0;
    bool flag = 1;
    for (int i = 0; flag; i++){
        flag = 0;
        for (int j = N-1; j >= 1; j--){
            if (A.at(j) < A.at(j-1)){
                swap(A.at(j), A.at(j-1));
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    vector<int> A(100);
    int N, sw;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A.at(i);
    sw = bubbleSort(A, N);
    for (int j = 0; j < N; j++){
        if (j > 0)  cout << " ";
        cout << A.at(j);
    }
    cout << endl;
    cout << sw << endl;
    
    return 0;
}

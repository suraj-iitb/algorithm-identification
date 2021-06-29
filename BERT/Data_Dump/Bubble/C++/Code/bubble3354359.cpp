#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void bubbleSort (vector<int> A, int N){
    bool flag = true;
    int count = 0;
    while (flag == true){
        flag = false;
        for (int j = N-1; j > 0; j--){
            if (A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = true;
                count++; 
            }
        }
    }
    for (int i = 0; i < N; i++){
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    
}

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    bubbleSort(A, N);

    
}

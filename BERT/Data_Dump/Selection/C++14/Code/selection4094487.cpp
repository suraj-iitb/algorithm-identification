#include <bits/stdc++.h>
using namespace std;

void print_v (vector<int> A){
    for(auto iter_A = A.begin(); iter_A != (A.end()-1); iter_A++){
        cout << *iter_A << " ";
    }
    cout << *(A.end()-1) << "\n";
}

// code
vector<int> selectionSort(vector<int> A, int N){

    int count = 0;

    int min_idx = 0;
    for (int i = 0; i < N; i++){
        min_idx = i;
        for (int j = i; j < N; j++){
            if(A[min_idx] > A[j]){
                min_idx = j;
            }
        }
        if(i != min_idx){
            swap(A[min_idx], A[i]);
            count++;
        }
    }

    print_v(A);
    cout << count << "\n";

    return A;
}

// main
int main(){
    // input
    int n;
    cin >> n;
    vector<int> v;
    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        v.push_back(x);
    }

    selectionSort(v, n);

    return 0;
}

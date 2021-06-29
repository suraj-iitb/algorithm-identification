#include <bits/stdc++.h>
using namespace std;

void print_v (vector<int> A){
    for(auto iter_A = A.begin(); iter_A != (A.end()-1); iter_A++){
        cout << *iter_A << " ";
    }
    cout << *(A.end()-1) << "\n";
}

// code
vector<int> bubbleSort(vector<int> A, int N){

    bool flag = true;
    int i = 0;
    int count = 0;

    while(flag){
        flag = false;
        for (int j = N-1; j > i; --j){
            //cout << "j: " << j << "\n";
            if(A[j] < A[j-1]){
                count++;
                swap(A[j], A[j-1]);
                flag=true;
            }
        }
        i++;
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

    bubbleSort(v, n);

    return 0;
}

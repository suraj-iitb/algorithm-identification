#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> A){
    for (int i = 0; i < A.size(); i++){
        cout << A.at(i);
        if (i != A.size() - 1) cout << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &A){
    int j,v;
    for(int i = 1; i < A.size(); ++i){
        v = A.at(i);
        j = i - 1;
        while((j >= 0) && (A.at(j) > v)){
            A.at(j+1) = A.at(j);
            j--;
        }
        A.at(j+1) = v;
        trace(A);
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A.at(i);

    trace(A);
    insertionSort(A);

    return 0;
}



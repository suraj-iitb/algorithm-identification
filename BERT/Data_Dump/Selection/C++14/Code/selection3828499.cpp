#include <bits/stdc++.h>
using namespace std;
void SelectionSort(vector<int> &A, int N){
    int bf;
    int minj;
    int Count = 0;

    for ( int i = 0; i < N; i++ ){
        minj = i;
        for ( int j = i; j < N; j++ ){
            if ( A.at(j) < A.at(minj) ) minj = j;
        }
        if ( minj != i ){
            bf = A.at(i);
            A.at(i) = A.at(minj);
            A.at(minj) = bf;
            Count++;
        }
    }

    for ( int i = 0; i < N - 1; i++ ){
        cout << A.at(i) << " ";
    }
    cout << A.at(N-1) << endl;
    cout << Count << endl;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for ( int i = 0; i < N; i++ ) cin >> A.at(i);
    
    SelectionSort( A, N );

    return 0;
}

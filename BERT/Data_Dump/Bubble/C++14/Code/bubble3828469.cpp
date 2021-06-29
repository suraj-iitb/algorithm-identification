#include <bits/stdc++.h>
using namespace std;
void BubbleSort(vector<int> &A, int N){
    int bf;
    bool flag = true;
    int Count = 0;

    while ( flag ){
        flag = false;
        for ( int i = N - 1; i >= 1; i-- ){
            if ( A.at(i) < A.at(i-1) ){
                bf        = A.at(i);
                A.at(i)   = A.at(i-1);
                A.at(i-1) = bf;
                flag = true;
                Count++;
            }
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
    
    BubbleSort( A, N );

    return 0;
}

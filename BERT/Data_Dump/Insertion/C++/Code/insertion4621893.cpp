#include <bits/stdc++.h>
#include <string> 
#include <cctype>
#include <cmath>
//#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;


vector<int> insertionSort(vector<int> A, int N){
    for(int i=1; i<N;i++){
        int j= i-1;
        int v = A.at(i);
        while (j>=0 && A.at(j)>v){
            A.at(j+1) = A.at(j);
            j--;
        }
        A[j+1] = v;
        for (int k=0; k<N; k++) {
            cout << A.at(k);
            if (k==N-1) break;
            cout << ' ';
        }
        cout << endl;
    }
    return A;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin >> A.at(i);
    for (int k=0; k<N; k++) {
            cout << A.at(k);
            if (k==N-1) break;
            cout << ' ';
        }
    cout << endl;
    vector<int> A_sorted = insertionSort(A, N);
    return 0;
}

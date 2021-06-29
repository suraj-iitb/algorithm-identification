#include <bits/stdc++.h>
using namespace std; 
void insertionSort(vector<int> &A, int &N){
    int v = A.at(N);
    int j = N - 1;
    while (j >= 0 && A.at(j) > v){
        A.at(j+1) = A.at(j);
        j -= 1;
        A.at(j+1) = v;
    }
    N += 1;
    return;
}

int main(){
    int N;
    cin >> N;
    vector<int> Ai(N);
    for (int i=0; i<N; i++){
        cin >> Ai.at(i);
        if (i != N-1) cout << Ai.at(i) << " ";
        else cout << Ai.at(i) << endl;
    }
    for (int k=1; k<N;){
        insertionSort(Ai, k);
        for (int m=0; m<N; m++){
            if (m == N-1) cout << Ai.at(m) << endl;
            else cout << Ai.at(m) << " ";
        }
    }
    return 0;

}
